#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
using namespace std ;

int findDuplicate(string a,string b);

int main( )
{
    ifstream first( "./test.txt" ) ;
    vector<string> stringTable;
    vector<string> duplicates;
    string temp,temp1,temp2;
    int i,j=0,flag=0;

    // read file, put it in the string table
    while( !first.eof())
        {
            first >>temp ;
            stringTable.push_back( temp );
        }

    // scan all wards, find duplicates
    for (i=0; i<(int)stringTable.size();i++)
    {
        temp1=stringTable[i];
        //j=0;
        for (j=i+1; j<(int)stringTable.size(); j++)
        {
            temp2=stringTable[j];
            flag=findDuplicate(temp1,temp2);        
            if(flag==1)
            {
		    duplicates.push_back(temp1);
            }
        }
    }
    for (i=0; i<(int)duplicates.size();i++)
    {  
        cout << duplicates[i] << endl;  
    }
    /*for( i=0;i<(int)stringTable.size();i++)    
    {       
        last << stringTable[i];       
        last << " ";  
    }
    last.close(); */
}

int findDuplicate(string a,string b)
{
    int i,j = 0;
    int flag = 1;
    if(a.size() == b.size()){
    	for(i=0;a[i]!='\0';i++)
    	{
		cout << a[i];
		cout << b[j];
             if(a[i] == b[j]){
		     j++;
	     }
	     else{
		     flag = 0;
		     break;
	     }
    	}
    }
    else{
	    flag = 0;
    }

    return flag;
}

