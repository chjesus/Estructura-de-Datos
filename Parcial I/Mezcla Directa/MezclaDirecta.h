#ifndef MEZCLADIRECTA_H
#define MEZCLADIRECTA_H
#include <fstream>
#include <stdio.h>

using namespace std;

template <class T>
class MezclaDirecta{
	private:
		string file;
	public:
		MezclaDirecta(string path) { file = path; }
		void Ordenar(int &N) 
		{
			fstream p1, p2;
			int bloq = 1;
			while (bloq < N) {
				Partir (p1, p2, bloq);
				Mezclar(p1, p2, bloq, N );
				bloq *=2;
			}
			remove("part1.dat");
			remove("part2.dat");
		}
		void Partir(fstream &f1, fstream &f2, int &bloque)
		{
			T buf;
			int c1 = 0, c2;
			fstream f;
			f.open(file.c_str(), ios::in | ios::binary);
			f1.open("part1.dat", ios::out | ios::binary); 
			f2.open("part2.dat", ios::out | ios::binary); 
			f.clear(); f1.clear(); f2.clear();
			f.seekg(0, ios::beg); 
			while (true) {
				f.read((char*)&buf, sizeof(buf));
				if (f.eof()) break;
				if (c1 < bloque)
				{
				    f1.write((char*)&buf, sizeof(buf));
				    c1++; 
				    if (c1 == bloque) c2 = 0; 
				}
				else
				{
				    f2.write((char*)&buf, sizeof(buf));
				    c2++; 
				    if (c2 == bloque) c1 = 0; 
				}
			}
			f.close();
			f1.close();
			f2.close();  
		}
		void Mezclar(fstream &f1, fstream &f2, int &bloque, int &N) 
		{
			T buf1, buf2;
			int c1 = 0, c2 = 0;
			fstream f;
			f.open(file.c_str(), ios::out | ios::binary);
			f1.open("part1.dat", ios::in  | ios::binary); 
			f2.open("part2.dat", ios::in  | ios::binary); 
			f1.clear(); f2.clear(); f.clear();
			f1.seekg(0, ios::beg);
			f2.seekg(0, ios::beg); 
			f1.read((char*)&buf1, sizeof(buf1));
			f2.read((char*)&buf2, sizeof(buf2));
			for (int i = 0; i < N; i++)
			{
				if (buf1 < buf2)
				{
					if (c1 < bloque) {
						f.write((char*)&buf1, sizeof(buf1));
						c1++;
						f1.read((char*)&buf1, sizeof(buf1)); 
					}
					else {
						f.write((char*)&buf2, sizeof(buf2));
						c2++;
						f2.read((char*)&buf2, sizeof(buf2));
					}
				}
				else 
				{
					if (c2 < bloque) {
						f.write((char*)&buf2, sizeof(buf2));
						c2++;
						f2.read((char*)&buf2, sizeof(buf2));
					}
					else {
						f.write((char*)&buf1, sizeof(buf1));
						c1++;
						f1.read((char*)&buf1, sizeof(buf1)); 
					}
				}
//				if (f1.eof()) buf1.setValue((char*)"zzzzzzzzz");
//				if (f2.eof()) buf2.setValue((char*)"zzzzzzzzz");
				if (f1.eof()) buf1.setValue((int)999999999);
				if (f2.eof()) buf2.setValue((int)999999999);
				if (c1 == bloque && c2 == bloque) c1 = c2 = 0;
			}
			f.close();
			f1.close();
			f2.close();  
		}
};
#endif
