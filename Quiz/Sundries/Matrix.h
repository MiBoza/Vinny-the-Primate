#include <iostream>
#include <cstddef>
using namespace std;
/* 	Use indexing: (*rowy)[3] = 7;*/

int floor(double x){
	if(x < 0){return (int)(x-0.999999999);}
	else{return (int)(x);}
}

double mod(double a, double b){
	int x = floor(a/b);
	return a - x*b;
}

class Matrix{
	public:
		float x;
		int i, j;
		int* sizeh;
		int* sizev;
		Matrix* beginh;
		Matrix* beginv;
		Matrix* next = NULL;
		Matrix* prev = NULL;
		Matrix* up = NULL;
		Matrix* down = NULL;

		Matrix* Make(float y){
			Matrix* R = new Matrix;
			R->beginh = R->beginv = R;
			R->x = y;
			R->sizev = new int;
			R->sizeh = new int;
			*(R->sizev) = *(R->sizeh) = 1;
			R->i = R->j = 0;
			return R;}
			
		Matrix* Push(float x){
			if(*(this->sizev) != 1){
				cerr<<"Matrix must be single row to push\n";
				exit(1);}
			Matrix* R = new Matrix;
			this->next = R;
			R->beginh = this->beginh;
			R->beginv = R;
			R->prev = this;
			R->x = x;
			R->i = 0;
			R->j = this->j + 1;
			R->sizeh = this->sizeh;
			R->sizev = this->sizev;
			*(R->sizeh) += 1;
			return R;}
		
		void Print(){
			Matrix* A = this->beginh->beginv;
			while(A->next){
				cout<<A->x<<", ";
				A = A->next;}
			cout<<A->x<<"\n";
						
			while(A->down){
				A = A->down->beginh;
				while(A->next){
					cout<<A->x<<", ";
					A = A->next;
				}
				cout<<A->x<<"\n";
			}
		}
				
		void DestroyR(){
			if (this->next){
				this->next->DestroyR();}
			delete this;}
			
		void DestroyM(){
			if(this->down){
				this->down->DestroyM();}
			this->DestroyR();
		}
		
		Matrix* Append(Matrix* B){
			Matrix* A = this->beginh;
			B = B->beginh->beginv;
			if(*(A->sizeh) != *(B->sizeh)){
				cerr<<"Row lengths must match to append\n";
				exit(1);}
			
			A->down = B;
			B->up = A;
			int tempi = A->i + 1;
			B->i = tempi;
			B->sizeh = A->sizeh;
			B->sizev = A->sizev;
			B->beginv = A->beginv;
			
			while(A->next){
				A = A->next;
				B = B->next;
				A->down = B;
				B->up = A;
				B->i = tempi;
				B->sizeh = A->sizeh;
				B->sizev = A->sizev;
				B->beginv = A->beginv;
			}
			*(A->sizev) += 1;
			return B;
		}
		
		Matrix* operator+(Matrix* B){
			Matrix* A = this->beginv->beginh;
			B = B->beginv->beginh;
			if(*(A->sizev) != *(B->sizev) || *(A->sizeh) != *(B->sizeh)){
				cerr<<"Matrix dimensions must match for addition\n";
				exit(1);}
			
			Matrix* D;
			Matrix* C = C->Make(A->x + B->x);
			while(A->next){
				A = A->next;
				B = B->next;
				C = C->Push(A->x + B->x);}
			
			while(A->down){
				A = A->down->beginh;
				B = B->down->beginh;
				D = D->Make(A->x + B->x);
				while(A->next){
					A = A->next;
					B = B->next;
					D = D->Push(A->x + B->x);
				}
				C = C->Append(D);
			}
			return C;
		}
		
		Matrix* operator-(Matrix* B){
			Matrix* A = this->beginv->beginh;
			B = B->beginv->beginh;
			if(*(A->sizev) != *(B->sizev) || *(A->sizeh) != *(B->sizeh)){
				cerr<<"Matrix dimensions must match for substraction\n";
				exit(1);}
			
			Matrix* D;
			Matrix* C = C->Make(A->x - B->x);
			while(A->next){
				A = A->next;
				B = B->next;
				C = C->Push(A->x - B->x);}
			
			while(A->down){
				A = A->down->beginh;
				B = B->down->beginh;
				D = D->Make(A->x - B->x);
				while(A->next){
					A = A->next;
					B = B->next;
					D = D->Push(A->x - B->x);
				}
				C = C->Append(D);
			}
			return C;
		}
		
		//Here we go
		Matrix* operator*(Matrix* B){
			Matrix* A = this->beginh->beginv;
			if(*(A->sizeh) != *(B->sizev)){
				cerr<<"Columns of first matrix must match rows of second matrix for multiplication\n";
				exit(1);}

			Matrix* D;
			float y;
			Matrix* tempA = A;
			B = B->beginv->beginh;

			y = tempA->x*B->x;
			while(B->down){
				tempA = tempA->next;
				B = B->down;
				y += tempA->x*B->x;}
			
			Matrix* C = C->Make(y);
			while(B->next){
				A = A->next;
				B = B->next->beginv;
				tempA = tempA->beginh;
				y = tempA->x*B->x;
				while(B->down){
					tempA = tempA->next;
					B = B->down;
					y += tempA->x*B->x;
				}
				C = C->Push(y);
			}
			
			while(A->down){
				A = A->down->beginh;
				tempA = A;
				B = B->beginh->beginv;
			
				y = tempA->x*B->x;
				while(B->down){
				tempA = tempA->next;
				B = B->down; 
				y += tempA->x*B->x;}
			
				D = D->Make(y);
				while(B->next){
					A = A->next;
					B = B->next->beginv;
					tempA = tempA->beginh;
					y = tempA->x*B->x;
					while(B->down){
						tempA = tempA->next;
						B = B->down;
						y += tempA->x*B->x;
					}
					D = D->Push(y);
				}
				C = C->Append(D);
			}
			return C;
		}
		
		float dot(Matrix* B){
			Matrix* A = this->beginv->beginh;
			B = B->beginv->beginh;
			if(*(A->sizev) != 1 || *(B->sizev) != 1){
				cerr<<"Matrixes must be single row for dot product\n";
				exit(1);}
			if(*(A->sizeh) != *(B->sizeh)){
				cerr<<"Vector lengths must match for dot product\n";
				exit(2);}
			float x = A->x*B->x;
			while(A->next){
				A = A->next;
				B = B->next;
				x += A->x*B->x;
			}
			return x;
		}
		
		Matrix* Move(int a, int b){
			Matrix* A = this;
			if(A->i > 2*a){
				return A->beginv->Move(a, b);}
			while(A->i < a){
				A = A->down;}
			while(A->i > a){
				A = A->up;}
			
			if(A->j > 2*b){
				return A->beginh->Move(a, b);}	
			while(A->j < b){
				A = A->next;}
			while(A->j > b){
				A = A->prev;
			}
			return A;
		}
		
		Matrix* ItoM(Matrix* B, int l){
			if(*(B->sizev) != 1){
				cerr<<"Matrix must be single row be used as input\n";
				exit(1);}
			if(mod((*(B->sizeh)), l) != 0){
				cerr<<"Number of inputs must be a multiple of side length\n";
				exit(1);}
				
			B = B->beginh;
			Matrix* A = A->Make(B->x);
			Matrix* C;
			for(int i = 1; i < l; i++){
				B = B->next;
				A = A->Push(B->x);
			}
			
			while(B->next){
				B = B->next;
				C = C->Make(B->x);
				for(int i = 1; i < l; i++){
					B = B->next;
					C = C->Push(B->x);
				}
				A = A->Append(C);
			}
			B->beginh->beginv->DestroyM();
			return A;
		}
		
		float Det(){
			Matrix* A = this;
			Matrix* C, *B;
			int sign = 1;
			float result = 0;
			int l = *(A->sizev);
			if(l != *(A->sizeh)){
				cerr<<"Matrix must be square to calcutlate determinant\n";
				exit(1);}
			A = A->beginh->beginv;
			if(*(A->sizev) == 1){return A->x;}
			if(*(A->sizev) == 2){return A->x*A->next->down->x - A->down->x*A->next->x;}
			
			for(int j = 0; j < l; j++){
				A = A->down;
				if(j == 0){A = A->next;}
				B = B->Make(A->x);
				while(A->next){
					A = A->next;
					if(A->j == j){continue;}
					B = B->Push(A->x);
				}
				
				while(A->down){
					A = A->down->beginh;
					if(j == 0){A = A->next;}
					C = C->Make(A->x);
					while(A->next){
						A = A->next;
						if(A->j == j){continue;}
						C = C->Push(A->x);
					}
					B = B->Append(C);
				}
				A = A->Move(0, j);
				result += A->x*sign*B->Det();
				sign *= -1;
				A = A->beginh->beginv;
				B->beginh->beginv->DestroyM();
			}
			return result;
		}
		/*
		float Cramer(Matrix* A, Matrix* V){
			if((*A->sizeh) != (*A->sizev))
		}*/
		
};
