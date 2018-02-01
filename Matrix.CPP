#include <iostream.h>
#include <conio.h>
class matrix
{
  int data[2][2];
 public:
  matrix (int, int,int,int);
  int get(int,int);
  void set(int,int,int,int);
  void print();
  static matrix tera(matrix);
  static int determinan(matrix);
  friend matrix operator+(matrix,matrix);
  friend matrix operator*(matrix,matrix);
  friend matrix operator-(matrix,matrix);
};

matrix operator-(matrix m1,matrix m2)
{
	matrix m3(0,0,0,0);
	m3.set(m1.data[0][0] - m2.data[0][0],
		m1.data[0][1] - m2.data[0][1],
		m1.data[1][0] - m2.data[1][0],
		m1.data[1][1] - m2.data[1][1] );
	return m3;
}

matrix::matrix (int a1, int a2,int a3,int a4)
{
  data[0][0] = a1;
  data[0][1] = a2;
  data[1][0] = a3;
  data[1][1] = a4;
}

int matrix::get(int row,int col)
{
  return data[row][col];
}

void matrix::set (int a1, int a2,int a3,int a4)
{
  data[0][0] = a1;
  data[0][1] = a2;
  data[1][0] = a3;
  data[1][1] = a4;
}

void matrix::print()
{
  cout << "          " << data[0][0] << " " ;
  cout << data[0][1] << endl;
  cout << "          " << data[1][0] << " ";
  cout << data[1][1] << endl << endl;
}

matrix operator+(matrix m1,matrix m2)
{
	matrix m3(0,0,0,0);
	m3.set(m1.data[0][0] + m2.data[0][0],
		m1.data[0][1] + m2.data[0][1],
		m1.data[1][0] + m2.data[1][0],
		m1.data[1][1] + m2.data[1][1] );
	return m3;
}

matrix operator*(matrix m1,matrix m2)
{
  matrix m3(0,0,0,0);
  m3.set(m1.data[0][0] * m2.data[0][0] + m1.data[0][1] * m2.data[1][0],
	 m1.data[0][0] * m2.data[0][1] + m1.data[0][1] * m2.data[1][1],
	 m1.data[1][0] * m2.data[0][0] + m1.data[1][1] * m2.data[1][0],
	 m1.data[1][0] * m2.data[0][1] + m1.data[1][1] * m2.data[1][1] );
  return m3;
}

matrix matrix::tera(matrix m1)
{
  matrix m2(0,0,0,0);
  m2.set(m1.get(0,0),		//for (int i = 0; i<=1; i++)
	 m1.get(1,0),		//for (int j = 0; j<=1; j++)
	 m1.get(0,1),           //m2.data[j][i] = m1.data[i][j];
	 m1.get(1,1) );
  return m2;
}

int matrix::determinan(matrix m1)
{
	return m1.data[0][0]*m1.data[1][1]-m1.data[0][1]*m1.data[1][0];
}

int main()
{
  matrix m1(5,2,4,3);
  matrix m2(2,3,1,2);
  matrix m3(0,0,0,0);

  cout << "Matrix1:" << endl;
  m1.print();
  
  cout<<"determinan (Matrix1): "<<matrix::determinan(m1);

  cout << "\n\nMatrix2:" << endl;
  m2.print();
  
  cout<<"determinan (Matrix2): "<<matrix::determinan(m2);

  //m3 = matrix::sum(m1,m2);
  m3=m1+m2;
  cout << "\n\nSum(+):" << endl;
  m3.print();

  m3 = m1*m2;
  cout << "Mul(*):" << endl;
  m3.print();
  
  m3=m1-m2;
  cout << "Minus(-):" << endl;
  m3.print();

  m3 = matrix::tera(m1);
  cout << "Tera(Matrix1):" << endl<< endl;
  m3.print();

  m3 = matrix::tera(m3);
  cout << "Tera(Tera(Matrix1))=Matrix1:" << endl << endl;
  m3.print();
  getch();
  return 0;
}
