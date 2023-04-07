all: ../cli.exe

../cli.exe: ./UPCalcula1/cli.cpp
    cl /EHsc /Fe /cli.exe ./UPCalcula1/cli.cpp
