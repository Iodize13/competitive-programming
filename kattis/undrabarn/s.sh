for ((i = 1; ; i++)); do
    echo $i
    echo $i > int
    ./a.out < int > ou1
    ./brute < int> ou2
    diff -w ou1 ou2 || break
done
