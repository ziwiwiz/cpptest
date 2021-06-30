#! /bin/sh
case $1 in
    "clean")
        rm -rf ./build/*
        ;;
    "build")
        cd build
        cmake ..
        make
        ;;
    "make")
        cd build
        make
        ;;
    "run")
        cd build/bin
        ./main
        ;;
    "test")
        cd build/bin/test
        for name in `ls`
            do
                ./$name
            done
        ;;
    *)
        ./make "build"
    ;;
esac