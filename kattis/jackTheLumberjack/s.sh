for ((i = 0; ; i++)); do
    tput setaf 2
    echo "[TESTCASE $i]:  PASS"
    ./gen $i > int
    ./a.out < int > ou1
    ./brute < int > ou2
    diff -w ou1 ou2 || break
done

# 1 2 3  4  5 6 7 8 9 10
# 2 8 14 20 26
#     6
#           
