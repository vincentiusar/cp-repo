n = int(input())
for i in range(n) :
    str = input()
    if ("1(" in str or "2(" in str or "3(" in str or "4(" in str or "5(" in str or "6(" in str or"7(" in str or "8(" in str or "9(" in str or "0(" in str) :
        print("invalid")
    elif (")1" in str or ")2" in str or ")3" in str or ")4" in str or ")5" in str or ")6" in str or")7" in str or ")8" in str or ")9" in str or ")0" in str) :
        print("invalid")
    else :
        try :
            if ("**" in str) :
                print("invalid")
            elif ("*+" in str) :
                print("invalid")
            elif ("*-" in str) :
                print("invalid")
            elif (str[0] == '-' or str[0] == '+' or str[0] == '*') :
                print("invalid")
            elif (str[-1] == '-' or str[-1] == '+' or str[-1] == '*'):
                print("invalid")
            elif ("-*" in str) :
                print("invalid")
            elif ("--" in str) :
                print("invalid")
            elif ("-+" in str) :
                print("invalid")
            elif ("+*" in str) :
                print("invalid")
            elif ("+-" in str) :
                print("invalid")
            elif ("++" in str) :
                print("invalid")
            elif ("(-" in str) :
                print("invalid")
            elif ("(+" in str) :
                print("invalid")
            elif ("(*" in str) :
                print("invalid")
            elif ("()" in str) :
                print("invalid")
            elif ("-)" in str) :
                print("invalid")
            elif ("+)" in str) :
                print("invalid")
            elif ("*)" in str) :
                print("invalid")
            elif (")(" in str) :
                print("invalid")
            elif (str.count('(') != str.count(')')):
                print("invalid")
            else :
                print(eval(str) % 1000000007)
        except :
            print("invalid")