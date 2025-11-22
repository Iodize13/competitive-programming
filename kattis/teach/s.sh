for ((i = 0; ; i++)); do
    tput setaf 2
    echo "[TEST $i]: PASS"
    ./gen $i > int
    ./a.out < int > ou1
    ./brute < int > ou2
    diff -w ou1 ou2 || break;
done
