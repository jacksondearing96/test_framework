COLOUR_RESET =  "\x1b[0m"
GREEN = "\x1b[42m"
RED = "\033[0;31m"

FATAL = True

def Pass(description):
    print(GREEN + 'Passed:' + COLOUR_RESET + ' ' + description)

def PrintFail(description):
    print(RED + 'Fail:' + COLOUR_RESET)
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


EXPECT_EQ(1,2,'FAIL TEST')
EXPECT_EQ(1,1,'PASS TEST')
EXPECT_TRUE(False, 'ex true fail')
EXPECT_TRUE(True, 'ex true pass')
EXPECT_EQ_LIST([3], [1], 'TYPE fail')
EXPECT_EQ_LIST([1,2,3],[3,2,1], 'LIST fail')
EXPECT_EQ_LIST([1,2,3],[1,2,3], 'list pass')
ASSERT_TRUE(False, 'assert true error')
ASSERT_EQ(1,2, 'assertion error')
ASSERT_EQ(1,2, 'this should not run')
