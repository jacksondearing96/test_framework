COLOUR_RESET =  "\x1b[0m"
GREEN = "\x1b[42m"
RED = "\033[0;31m"

FATAL = True

def Green(s):
    return GREEN + s + COLOUR_RESET

def Red(s):
    return RED + s + COLOUR_RESET

def Pass(description):
    print(Green('Passed:') + ' ' + description)

def PrintFail(description):
    print(Red('Fail:'))
    print('\t' + description)

def Fail(a, b, description):
    PrintFail(description)
    print('\tExpected:\t' + str(a))
    print('\tActual:\t\t' + str(b))

def TypeFail(a, b, description):
    PrintFail(description)
    print('\tType Failure:')
    print('\tExpected Type:\t' + type(a))
    print('\tActual Type:\t\t' + type(b))

def SizeFail(a, b, description):
    PrintFail(description)
    print('\tSize Failure:')
    print('\tExpected Size:\t' + str(len(a)))
    print('\tActual Size:\t\t' + str(len(b)))

def ListValueFail(a, b, index, description):
    PrintFail(description)
    print('\tList Failure at index ' + str(index) + ':')
    print('\tExpected:\t' + str(a))
    print('\tActual:\t\t' + str(b))

def EXPECT_EQ(a, b, description, fatal = False):
    if a == b:
        Pass(description)
    else: 
        Fail(a, b, description)
        if fatal: exit(1)

def EXPECT_TRUE(a, description, fatal = False):
    if a == True: 
        Pass(description)
    else:
        Fail(a, True, description)
        if fatal: exit(1)

def ASSERT_TRUE(a, description):
    EXPECT_TRUE(a, description, FATAL)


def ASSERT_EQ(a, b, description):
    EXPECT_EQ(a, b, description, FATAL)

def EXPECT_EQ_LIST(a, b, description):
    if type(a) is not type(a):
        return TypeFail(a, b, description)
    if len(a) is not len(b):
        return SizeFail(a, b, description)
    for index in range(0, len(a)):
        if a[index] is not b[index]:
            return ListValueFail(a, b, index, description)
    Pass(description)
