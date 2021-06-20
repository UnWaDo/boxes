gcc -Wall -Wextra -Werror *.c
p="1 3 2 3 2 1 3 2 1 2 3 2 3 2 1 2"
echo $p
./a.out "$p"
p="2 3 1 2 1 2 3 1 2 1 1 4 3 1 2 4"
echo $p
./a.out "$p"
p="4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"
echo $p
./a.out "$p"
p="1 3 2 3 2 1 3 2 1 2 3 2 3 2 1 3"
echo $p
./a.out "$p"
p="4 3 2 1 1 2 2 2 2 2 2 2 1 2 3 4"
echo $p
./a.out "$p"
p="1 2 2 2 4 3 2 1 1 2 2 2 4 3 2 1"
echo $p
./a.out "$p"
