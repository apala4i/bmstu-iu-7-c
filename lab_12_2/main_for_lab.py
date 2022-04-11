import sys
import ctypes

lib = ctypes.CDLL("libfuncs_for_py.so")
_shift_left = lib.shiftArray
_shift_left.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.c_int)
_shift_left.restype = None

# int squareArray(int *array, int size, int *newArray)
_squareArray = lib.squareArray
_squareArray.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_int, ctypes.POINTER(ctypes.c_int))
_squareArray.restype = ctypes.c_int


def squareArray(srcArr):
    _srcArr = (ctypes.c_int * len(srcArr))(*srcArr)
    dstSize = _squareArray(_srcArr, len(srcArr), None)
    _dstArr = (ctypes.c_int * int(dstSize))()
    _squareArray(_srcArr, len(srcArr), _dstArr)
    return list(_dstArr)



def shiftLeft(digits, steps):
    count = len(digits)
    arr = (ctypes.c_int * count)(*digits)
    _shift_left(arr, count, steps)
    return list(arr)

choice = -1
while choice:
    choice = int(input("1) shift array\n2) sqrt array\n0) exit\n"))
    if choice == 1:
        arr = list(map(int, input("input array\n").split()))
        step = int(input("input step\n"))
        print(*shiftLeft(arr, step))
    if choice == 2:
        arr = list(map(int, input("input array\n").split()))
        print(*squareArray(arr))
