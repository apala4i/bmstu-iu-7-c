#include "func.h"

int create_param(char *file_name)
{
    FILE *input_file = fopen(file_name, "wb");

    // collect name of new product
    struct product_info current_product = { 0 };
    int n;
//    printf("Input count of structures\n");
    fscanf(stdin, "%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Input product name\n");
        fscanf(stdin, "%s", current_product.name);
        if (strlen(current_product.name) > MAX_NAME)
            return INPUT_ERROR;

        // collect manufacturer of new product
        printf("Input product manufacturer\n");
        fscanf(stdin, "%s", current_product.made_by);
        if (strlen(current_product.made_by) > MAX_MADE_BY)
            return INPUT_ERROR;

        // collect price of new product
        printf("Input price of product\n");
        if (fscanf(stdin, "%u", &current_product.price) != 1)
            return INPUT_ERROR;

        // collect count of new product
        printf("Input count of product\n");
        if (fscanf(stdin, "%u", &current_product.count) != 1)
            return INPUT_ERROR;
        put_struct_by_pos(input_file, i, &current_product);
        printf("struct was successfully recorded\n");
    }
    // close file
    fclose(input_file);
    return STABLE_WORK;
}

void struct_shift(FILE *file, struct product_info *product, const int current_pos, const int count)
{
    struct product_info shift_product = { 0 };
    for (int i = count; i > current_pos; i--)
    {
        get_struct_by_pos(file, i - 1, &shift_product);
        put_struct_by_pos(file, i, &shift_product);
    }
    put_struct_by_pos(file, current_pos, product);
}

int get_struct_by_pos(FILE *file, const int position, struct product_info *current_product)
{
    unsigned int current_poz;
    current_poz = ftell(file);
    fseek(file, sizeof (struct product_info) * position, SEEK_SET);
    if (fread(current_product, sizeof (struct product_info), 1, file) != 1)
        return INPUT_ERROR;
    fseek(file, current_poz, SEEK_SET);
    return STABLE_WORK;
}

int put_struct_by_pos(FILE *file, const int position, struct product_info *insert_product)
{
    unsigned int current_poz;
    current_poz = ftell(file);
    fseek(file, sizeof (struct product_info) * position, SEEK_SET);
    if (fwrite(insert_product, sizeof (struct product_info), 1, file) != 1)
        return INPUT_ERROR;
    fseek(file, current_poz, SEEK_SET);
    return STABLE_WORK;
}

int sb_param(char *input_file_name, char *output_file_name)
{
    // open input binary file and check it's existing
    FILE *input_file = fopen(input_file_name, "rb");
    if (input_file == NULL)
        return FILE_DOES_NOT_EXIST;

    // calculate count of structures
    fseek(input_file, 0L, SEEK_END);
    int count = ftell(input_file) / sizeof (struct product_info);
    rewind(input_file);

    // Return error if count invalid
    if (count < 1)
        return EMPTY_FILE;

    // create/open output file
    FILE *output_file = fopen(output_file_name, "wb+");
    if (output_file == NULL)
        return FILE_DOES_NOT_EXIST;

    // fill output bin file with the first struct out of input file
    struct product_info current_product = { 0 };
    if (get_struct_by_pos(input_file, 0, &current_product))
    {
        fclose(output_file);
        return INPUT_ERROR;
    }
    if (put_struct_by_pos(output_file, 0, &current_product))
    {
        fclose(output_file);
        return INPUT_ERROR;
    }
    int flag;

    struct product_info cmp_product = { 0 };
    // make sorted bin file with structures out of input_file
    for (int i = 1; i < count; i++)
    {
        flag = 0; // end insert check
        if (get_struct_by_pos(input_file, i, &current_product))
        {
            fclose(input_file);
            fclose(output_file);
            return INPUT_ERROR;
        }
        for (int j = 0; j < i; j++)
        {
            if (get_struct_by_pos(output_file, j, &cmp_product))
            {
                fclose(input_file);
                fclose(output_file);
                return INPUT_ERROR;
            }
            if (current_product.price > cmp_product.price)
            {
                flag = 1;
                struct_shift(output_file, &current_product, j, i);
                break;
            }
            if (current_product.price == cmp_product.price)
            {
                flag = 1;
                while (current_product.price == cmp_product.price && current_product.count <= cmp_product.count &&
                    j < i)
                {
                    if (get_struct_by_pos(output_file, j, &cmp_product))
                    {
                        fclose(input_file);
                        fclose(output_file);
                        return INPUT_ERROR;
                    }
                    j++;
                }
                struct_shift(output_file, &current_product, j, i);
                break;
            }
        }
        if (!flag)
            if (put_struct_by_pos(output_file, i, &current_product))
            {
                fclose(input_file);
                fclose(output_file);
                return INPUT_ERROR;
            }
    }
    // close files
    fclose(input_file);
    fclose(output_file);
    return STABLE_WORK;
}

int ab_param(char *output_file_name)
{
    char buf[40] = "";
    FILE *output_file = fopen(output_file_name, "rb+");
    if (output_file == NULL)
        return FILE_DOES_NOT_EXIST;

    // Calculate count of structures in bin output file
    fseek(output_file, 0L, SEEK_END);
    int count = ftell(output_file) / sizeof (struct product_info);
    rewind(output_file);

    // collect name of new product
    struct product_info current_product = { 0 };
//    printf("Input product name\n");
    fscanf(stdin, "%s", buf);
    if (strlen(buf) > MAX_NAME)
    {
        fclose(output_file);
        return INPUT_ERROR;
    }
    strcpy(current_product.name, buf);

    // collect manufacturer of new product
    printf("Input product manufacturer\n");
    fscanf(stdin, "%s", buf);
    if (strlen(buf) > MAX_MADE_BY)
    {
        fclose(output_file);
        return INPUT_ERROR;
    }
    strcpy(current_product.made_by, buf);

    // collect price of new product
    printf("Input price of product\n");
    if (fscanf(stdin, "%u", &current_product.price) != 1)
    {
        fclose(output_file);
        return INPUT_ERROR;
    }

    // collect count of new product
    printf("Input count of product\n");
    if (fscanf(stdin, "%u", &current_product.count) != 1)
    {
        fclose(output_file);
        return INPUT_ERROR;
    }

    struct product_info cmp_product = { 0 };
    for (int i = 0; i < count; i++)
    {
        get_struct_by_pos(output_file, i, &cmp_product);
        if (current_product.price > cmp_product.price)
        {
            struct_shift(output_file, &current_product, i, count);
            fclose(output_file);
            return STABLE_WORK;
        }
        if (current_product.price == cmp_product.price)
        {
            while (current_product.count < cmp_product.count && i < count && current_product.price == cmp_product.price)
            {
                i++;
                get_struct_by_pos(output_file, i, &cmp_product);
            }
            struct_shift(output_file, &current_product, i, count);
            fclose(output_file);
            return STABLE_WORK;
        }
    }
    struct_shift(output_file, &current_product, count, count);
    fclose(output_file);
    return STABLE_WORK;
}

int print_param(char *input_file_name)
{
    FILE *input_file = fopen(input_file_name, "rb");

    fseek(input_file, 0L, SEEK_END);
    int count = ftell(input_file) / sizeof (struct product_info);
    rewind(input_file);
    struct product_info current_product = { 0 };
    for (int i = 0; i < count; i++)
    {
        get_struct_by_pos(input_file, i, &current_product);
        printf("product info:\n");
        printf("name: %s\n", current_product.name);
        printf("made_by: %s\n", current_product.made_by);
        printf("price: %u\n", current_product.price);
        printf("count: %u\n\n", current_product.count);
    }
    fclose(input_file);
    return STABLE_WORK;
}