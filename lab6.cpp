/*
Author: Dylan O'Briem
Assignment: EECS 348 Lab 6
Description: The file's purpose is to fufill the expected computations of the given matrices in the input file. Matrices may
be read, printed, added, multiplied or subtracted.
*/
#include <iostream>
#include <string>
#include <fstream>

//my static constant of 100
const int hundred= 100;
//Five functional prototypes for my five functions
void readfile(std::ifstream& dafile, int matrix[hundred][hundred], int size);
void matrixprinter(int matrix[hundred][hundred], int size);
void matrixadd(int matrixa[hundred][hundred], int matrixb[hundred][hundred], int matrixresult[hundred][hundred],int size);
void matrixmultiply(int matrixa[hundred][hundred], int matrixb[hundred][hundred], int matrixresult[hundred][hundred],int size);
void matrixsubtract(int matrixa[hundred][hundred], int matrixb[hundred][hundred], int matrixresult[hundred][hundred],int size);

int main(){
    //define size, matrix a and martix b
    int dasize;
    int matrixa[hundred][hundred];
    int matrixb[hundred][hundred];
    //Ask user for file
    std:: string userfile;
    std:: cout << "Please enter the input file name: ";
    std:: cin >> userfile;
    //use ifstream as tracker for filling matrix a and b
    std::ifstream openfile(userfile);
    //Checking ability to open user enetered file 
    if(!openfile.is_open()){
        std :: cerr << "Cannot open file" << std :: endl;
        return 1;
    }
    //Checking if I can obtain size from spot 0,0
    if(!(openfile>>dasize)){
        std :: cerr << "Cannot obtain size" << std :: endl;
        return 1;
    }
    //skip to next line since all I need is the size from line 1
    std:: string lineskip;
    std:: getline(openfile,lineskip);
    //call readfile to fill in matrix a and b
    readfile(openfile,matrixa,dasize);
    readfile(openfile,matrixb,dasize);

    //close file after it has been iterated through
    openfile.close();
    //print my info
    std:: cout << "Dylan O'Brien" <<std :: endl;
    std:: cout << "Lab #6: Matrix manipulation" <<std :: endl;
    //print matrix a and b
    std:: cout << "Matrix A:" <<std :: endl;
    matrixprinter(matrixa,dasize);
    std:: cout << "" <<std :: endl;
    std:: cout << "Matrix B:" <<std :: endl;
    matrixprinter(matrixb,dasize);
    std:: cout << "" <<std :: endl;
    //create matrix for sum of matrix a and b
    //print matrix sum after using matrixadd
    int matrixaddres[hundred][hundred];
    matrixadd(matrixa, matrixb ,matrixaddres, dasize);
    std:: cout << "Matrix Sum (A+B):" <<std :: endl;
    matrixprinter(matrixaddres, dasize);
    std:: cout << "" <<std :: endl;
    //create matrix for product of matrix a and b
    //print matrix product after using matrixmultiply
    int matrixmultres[hundred][hundred];
    matrixmultiply(matrixa, matrixb ,matrixmultres, dasize);
    std:: cout << "Matrix Product (A*B):" <<std :: endl;
    matrixprinter(matrixmultres, dasize);
    std:: cout << "" <<std :: endl;
    //create matrix for difference of matrix a and b
    //print matrix difference after using matrixsubtract
    int matrixsubres[hundred][hundred];
    matrixsubtract(matrixa, matrixb ,matrixsubres, dasize);
    std:: cout << "Matrix Difference (A-B):" <<std :: endl;
    matrixprinter(matrixsubres, dasize);
    std:: cout << "" <<std :: endl;
    return 0;
}
//Go through file and make sure you can read every spot using the given size applied to the given matrix
//if spot can be read apply that to matrix parameter
void readfile(std::ifstream& dafile, int matrix[hundred][hundred], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(!(dafile>>matrix[i][j])){
                std :: cerr << "Cannot read file at row "<<i << " and column " << j <<std :: endl;
                exit(1);
            }
        }
    }
}
//Go line by line and print each value at given i,j spot in matrix or 2d array
void matrixprinter(int matrix[hundred][hundred], int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            std:: cout << matrix[i][j] << " ";
            }
        //Used to go to next line when a line is done printing values
        std:: cout <<std :: endl;
        }
    }
//Make resulting matrix at spot i,j the sum of each spot at matrix a and b at i,j
void matrixadd(int matrixa[hundred][hundred], int matrixb[hundred][hundred], int matrixresult[hundred][hundred],int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matrixresult[i][j]= matrixa[i][j] + matrixb[i][j];
        }
}
}
//Iterate through values of i and j to form a product matrix with all 0 values
//Then iterate through values of x to make values of product matrix i,j the product of matrix[i][x] and matrix[x][j]
//This allows for each row of matrix a to be multiplied by each colum of matrix b
void matrixmultiply(int matrixa[hundred][hundred], int matrixb[hundred][hundred], int matrixresult[hundred][hundred],int size){
     for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matrixresult[i][j]= 0;
            for(int x=0; x<size; x++){
                matrixresult[i][j]+= matrixa[i][x] * matrixb[x][j];
            }

        }
}
}
//Iterate through values of i and j to create resulting matrix with values at i,j to be equal to matrixa[i][j]-matrixb[i][j]
void matrixsubtract(int matrixa[hundred][hundred], int matrixb[hundred][hundred], int matrixresult[hundred][hundred],int size){
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            matrixresult[i][j]= matrixa[i][j] - matrixb[i][j];
        }
}
}





