for ((i = 1; ; i++)); do
    tput setaf 2
    echo "[TEST $i]: PASS"
    echo $i > int
    ./brute < int > ou1
    ./a.out < int > ou2
    diff -w ou1 ou2 || break
done
