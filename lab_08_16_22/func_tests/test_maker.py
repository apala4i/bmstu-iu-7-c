from random import randint
import os

def generate_matrix(rows, columns, flag, file_name):
    file_name = open(file_name, "w")
    if flag == 1:
        file_name.write(f"{rows} {columns} {0}")
        file_name.close()
        return
    else:
        file_name.write(f"{rows} {columns} {rows * columns}")

    for i in range(rows):
        for j in range(columns):
            new_item = randint(1, 20)
            file_name.write(f"\n{i + 1} {j + 1} {new_item}")
    file_name.close()

def matrix_bin_op(first_file, second_file, res_file, rows, columns, app_name, operation, flag):
    generate_matrix(rows, columns, flag, first_file)
    generate_matrix(rows, columns, flag, second_file)
    os.system(f"{app_name} {operation} {first_file} {second_file} {res_file}")

def matrix_un_op(first_file, res_file, rows, columns, app_name, operation, flag):
    generate_matrix(rows, columns, flag, first_file)
    os.system(f"{app_name} {operation} {first_file} {res_file}")

def test_name(first_second_res, num, pos_neg, path):
    res = path
    res += "pos" if pos_neg == 1 else "neg"
    str_num = f"_0{num}_" if num < 10 else f"_{num}_"
    res += str_num
    if (first_second_res == 1):
        res += "first.txt"
    if (first_second_res == 2):
        res += "second.txt"
    if (first_second_res == 3):
        res += "res.txt"
    return res

path = "C:/lab/lab_08_16_22/func_tests/"
app_name = "app.exe"



rows = int(input("количество строк\n"))
columns = int(input("количество столбцов\n"))
flag = int(input("1 - нулевая\n2 - ненулевая\n3 - единичная\n"))
pos_neg = int(input("1 - позитивный\n 2 - негативный\n"))
num = int(input("номер теста\n"))
action = int(input("1 - умножение\n2 - сложение\n3 - определитель\n4 - белеберда\n"))

first_file_name = test_name(1, num, pos_neg, path)
second_file_name = test_name(2, num, pos_neg, path)
res_file_name = test_name(3, num, pos_neg, path)

# print(first_file_name)
# print(second_file_name)
# print(res_file_name)

if action == 1:
    action_name = "m"
if action == 2:
    action_name = "a"
if action == 3:
    action_name = "o"

if (action == 1 or action == 2 or action == 4):
    matrix_bin_op(first_file_name, second_file_name, res_file_name, rows, columns, app_name, action_name, flag)
if (action == 3):
    matrix_un_op(first_file_name, res_file_name, rows, columns, app_name, action_name, flag)
