# Huffman Coding

This is an Implementation for the huffman coding algorithm for lossless compression
This implementation is done on PGM greyscale photo files with some examples in the **data folder**

## Table of contents
* [Running](#Running)
* [Status](#Status)
* [Others](#Others)
* [Others](#GUI)

## Running
> To compile Project run the following command
```terminal
g++ main.cpp huffman.cpp IOStream.cpp -o huffman.o
```

> To Run the program for compression you should pass one argument (photo path) and you should have a folder in the pwd named ``encoded``
```terminal
./huffman.o ./directory/filename.pgm
```

> To Run the program for decompression you should pass two arguments (frequency table and compressed file) and you shold have a folder in the pwd named ``decoded``
```terminal
./huffman.o ./encoded/filename.huf ./encoded/filename.frq
```

### Using CMake
> To compile project run the following commands
```terminal
mkdir build
cd build
mkdir encoded decoded
cmake ..
make

> To Run the program for compression you should pass one argument (photo path) and you should have a folder in the pwd named ``encoded``
terminal
./huffman.o ../data/filename.pgm

> To Run the program for decompression you should pass two arguments (frequency table and compressed file) and you shold have a folder in the pwd named ``decoded``
terminal
./huffman.o ./encoded/filename.huf ./encoded/filename.frq
```


## Status
* The Console application is done
* GUI application is still in process

## Others
For more information please refere to the [report pdf](https://github.com/sbme-tutorials/sbe201-2020-final-project-huffman-sbe201-2022-team01/blob/master/TheReport.pdf).

## GUI 
Haffman_test is our GUI it is more than half done the layout is completed with a simple user manual that describe how the GUI will work. simple functions were implemented as a prove of concept such as making a directory after pressing compression and write two files in it (.frq and .huf) after choosing a file to be compressed ( the path to images folder were provided to ease choosing a file with filter of the needed extentions added ). after pressing decompression a user will be asked to choose a (frq and .huf) files with a process similar to the previous one and then a directory is created with the original file. All the functions in the current GUI(huffman_test) was a prove of concept. 

Please note :
The main program using the terminal works  properly. what are we still working on is the implementation of the functions in our project to the GUI. we will provide all updates to the GUI and  the pdf file as soon as it will be finished.  when working on the project no relative path was provided as it caused errors. We are working on it right now.
# Haffman-Encoding-
