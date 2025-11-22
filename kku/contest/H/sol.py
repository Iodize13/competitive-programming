n = int(input())

for case in range(n):
    input_l = list(map(int , input().split(' ')))
    num_fish =  input_l.pop(0)
    ans = 0
    # print(input_l)
    
    while (num_fish != 0):
        dept = input_l.pop(0) + 1
        num_fish -= 1
        # print(input_l)

        check = 0
        while (check < len(input_l)):
            if (input_l[check] == dept):
                dept = input_l.pop(check) + 1
                num_fish -= 1
                check -= 1
                # print(dept)
            check += 1
        ans += 1
    print(ans)
