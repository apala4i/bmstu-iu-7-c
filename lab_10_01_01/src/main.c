#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "errors.h"
#include "participant.h"
#include "node.h"

//#if defined(WIN_32) || defined(_WIN_32) || defined(__WIN32__) || defined(__NT__)
//    #define CLS_COMMAND "cls"
//#elif __linux__
//    #define CLS_COMMAND "clear"
//#endif

#define DEBUG 0

void node_print_part(node_t *head)
{
    while (head != NULL)
    {
        printf("%s", ((participant *)head->data)->name);
        printf("%d\n", ((participant *)head->data)->age);
        head = head->next;
    }
    printf("\n");
}

void cls_command()
{
//    system(CLS_COMMAND);
    system("clear");
}

int comp_for_part(const void *first, const void *second)
{
    return ((participant *)first)->level - ((participant *)second)->level;
}

void print_part_to_file(FILE *output_file, node_t *storage)
{
    while (storage != NULL)
    {
        fprintf(output_file, "%s", ((participant *)storage->data)->name);
        fprintf(output_file, "%d\n", ((participant *)storage->data)->age);
        fprintf(output_file, "%d\n", ((participant *)storage->data)->level);
        storage = storage->next;
    }
}

int comp_for_anatoliy(const void *first, const void *second)
{
    if (strcmp(((participant *) first)->name, ((participant *) second)->name) == 0 &&
        ((participant *) first)->age == ((participant *) second)->age &&
        ((participant *) first)->level == ((participant *) second)->level)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    participant son;
    son.level = 2;
    son.age = 5;
    son.name = "Анатолий\n";

    if (argc != 3)
    {
        return BAD_ARGS;
    }

    int count = 0;
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        return FILE_ERROR;
    }

    int rc;
    rc = count_part(input_file, &count);
    if (rc)
    {
        return rc;
    }

    participant *all_participants = NULL;
    if (participant_init(&all_participants, count) != EXIT_SUCCESS)
    {
        fclose(input_file);
        return MEM_ERROR;
    }

    fseek(input_file, 0, SEEK_SET);
    read_part(input_file, all_participants);
    fclose(input_file);

    int anatoliy_check = 0;
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(all_participants[i].name, "Анатолий\n") == 0 && all_participants[i].age == 5 && all_participants[i].level == 2)
        {
            anatoliy_check += 1;
        }
    }
    if (anatoliy_check == 2)
    {
        clean_part(all_participants, count);
        return 4;
    }

    node_t *head_beginner = NULL;
    node_t *head_medium = NULL;
    node_t *head_master = NULL;

    for (int i = 0; i < count; ++i)
    {
        if (DEBUG)
        {
            printf("Информация о текущем перце\n"
                "Имя - %s"
                "Возраст - %d\n"
                "Уровень - %d\n",
            all_participants[i].name, all_participants[i].age, all_participants[i].level);
        }
        switch (all_participants[i].level)
        {
            case 0:
                push_front(&head_beginner, &all_participants[i]);
                break;
            case 1:
                push_front(&head_medium, &all_participants[i]);
                break;
            case 2:
                push_front(&head_master, &all_participants[i]);
                break;
        }
    }

    int choice = -1;

    node_t *beg_son_place = find(head_master, &son, comp_for_anatoliy);
    while (choice != 0)
    {
        printf("Выберите действие:\n"
            "1 - напечатать участников с уровнем beginner\n"
            "2 - напечатать участников с уровнем medium\n"
            "3 - напечатать участников с уровнем master\n"
            "4 - сократить участников\n"
            "5 - записать участников в файл и выйти\n"
            "0 - выход\n");
        if (scanf("%d", &choice) != 1)
        {
            printf("Некорректные данные, попробуйте еще раз!\n");
            while (getchar() != '\n');
        }
        else
        {
            switch (choice)
            {
                case 0:
                    break;
                case 1:
                    cls_command();
                    if (head_beginner == NULL)
                    {
                        printf("В списках нет участников с уровнем beginner\n");
                    }
                    else
                    {
                        printf("beginners\n");
                        node_print_part(head_beginner);
                    }
                    break;
                case 2:
                    cls_command();
                    if (head_medium == NULL)
                    {
                        printf("В списках нет участников с уровнем medium\n");
                    }
                    else
                    {
                        printf("mediums\n");
                        node_print_part(head_medium);
                    }
                    break;
                case 3:
                    cls_command();
                    if (head_master == NULL)
                    {
                        printf("В списках нет участников с уровнем masters\n");
                    }
                    else
                    {
                        printf("masters\n");
                        node_print_part(head_master);
                    }
                    break;
                case 4:
                    {
                        cls_command();
                        int new_count;
                        printf("Число заявок - %d\nВведите новое число участников:\n", count);
                        if (scanf("%d", &new_count) != 1 || new_count >= count || new_count < 1)
                        {
                            printf("некорректное число участников, попробуйте еще раз!\n");
                            while (getchar() != '\n');
                        }
                        else
                        {
                            int pop_count = count - new_count;
                            printf("%d заявок успешно удалено!\n", pop_count);
                            while (pop_count != 0)
                            {
                                if (head_beginner != NULL)
                                {
                                    pop_end(&head_beginner);
                                    pop_count--;
                                }
                                if (head_medium != NULL && pop_count != 0)
                                {
                                    pop_end(&head_medium);
                                    pop_count--;
                                }
                                if (head_master != NULL && pop_count != 0)
                                {
                                    pop_end(&head_master);
                                    pop_count--;
                                }
                            }
                        }
                        break;
                    }
                case 5:
                    {
                        node_t *res_son_place = find(head_master, &son, comp_for_anatoliy);
                        cls_command();
                        append(&head_beginner, &head_medium);
                        append(&head_beginner, &head_master);
                        head_beginner = sort(head_beginner, comp_for_part);
                        FILE *output_file = fopen(argv[2], "w");
                        if (output_file == NULL)
                        {
                            clean_part(all_participants, count);
                            free(all_participants);
                            node_free(head_beginner);
                            node_free(head_medium);
                            node_free(head_master);
                            printf("Не удалось открыть файл\n");
                            return FILE_ERROR;
                        }
                        if (beg_son_place && !res_son_place)
                        {
                            printf("УДАЛЕН\n");
                            fprintf(output_file, "УДАЛЕН\n");
                        }
                        else if (beg_son_place && res_son_place)
                        {
                            printf("ОСТАЛСЯ\n");
                            fprintf(output_file, "ОСТАЛСЯ\n");
                        }
                        else if (!beg_son_place && !res_son_place)
                        {
                            printf("НЕ ПОДАВАЛ\n");
                            fprintf(output_file, "НЕ ПОДАВАЛ\n");
                        }
                        if (output_file)
                        {
                            print_part_to_file(output_file, head_beginner);
                            printf("Участники записаны в следующем порядке\n");
                            node_print_part(head_beginner);
                            choice = 0;
                            fclose(output_file);
                        }
                        else
                        {
                            printf("Произошла ошибка открытия файла\n");
                        }
                        break;
                    }
                default:
                    printf("что-то непонятное\n");
                    break;
            }
        }
    }
    printf("\nДо встречи на турнире \"Super Nardus!\"\n");
    clean_part(all_participants, count);
    free(all_participants);
    node_free(head_beginner);
    node_free(head_medium);
    node_free(head_master);
}