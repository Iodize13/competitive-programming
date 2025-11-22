for ((i = 0;;i++)); do
    echo $i
    ./gen < $i > int
    ./a.out < int > ou1
    ./brute < int > ou2
    diff -w ou1 ou2 || break
done
