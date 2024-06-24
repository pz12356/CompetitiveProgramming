#! /bin/bash
g++ bruce.cpp -o bruce.out -std=c++20
g++ std.cpp -o std.out -std=c++20
while (true)
do
    pypy3 gen.py > data.txt
    ./std.out < data.txt > std.txt
   ./bruce.out < data.txt > bruce.txt  

    if test $? -ne 0
    then
        exit 0
    fi

    if diff std.txt bruce.txt
    then 
        echo "$i Ac"
    else
        echo "GG"
        exit 0
    fi

done
