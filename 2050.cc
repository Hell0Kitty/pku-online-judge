#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Figure{ 
public:
	int docOrder, lineOrder;
	Figure() {}
	Figure( int d, int l ) {
		docOrder = d;
		lineOrder = l;
	}
};

bool operator < ( const Figure f1, const Figure f2 ) { 
	if( f1.docOrder!=f2.docOrder ) {
		return f1.docOrder < f2.docOrder;
	} else {
		return f1.lineOrder < f2.lineOrder;
	}
}

class Doc{ 
public :
	int docOrder, lineLimit;
	Doc() {}
	Doc( int d, int l ) {
		this->docOrder = d;
		this->lineLimit = l;
	}
};

typedef set < Figure > Src; 
typedef set < int > docSrc;
map < string, docSrc > docMap; 
map < string, Src > dict; 
map < Figure, string > wordLine; 
vector < Doc > docs;

const string DOC_END = "**********";
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

void Standard( string &line ); 
void WordRecord( string &line, int docOrder, int lineOrder ); 
void PrintSrc( Src &src ); 
void WordsToFigure( Src &src, docSrc &dsrc, string& w1, string& w2 ); 
void NotWord( string& word, Src &src ); 

int main() {
	int allDocs, queries;

	scanf( "%d", &allDocs );
	cin.get();
	for( int i=0; i<allDocs; i++ ) {
		string line;
		int lineCounter = 0;
		while( getline( cin, line ) && line != DOC_END ) { 
			wordLine[ Figure( i, lineCounter ) ] = line;
			Standard( line );
			WordRecord( line, i, lineCounter ++ );
		}
		docs.push_back( Doc( i, lineCounter ) );
	}

	string command;
	scanf( "%d", &queries );
	cin.get();
	while( queries -- ) {
		getline( cin, command );
		Standard( command );
		Src src;
		if( command.find_last_of( ' ' ) == string::npos ) {
			Standard( command );
			src = dict[ command ];
		} else if( command.find_last_of( ' ' ) != command.find_first_of( ' ' ) ) {
			stringstream ss( command );
			string w1, w2, connected;
			ss >> w1 >> connected >> w2;
			docSrc dSrc1 = docMap[ w1 ];
			docSrc dSrc2 = docMap[ w2 ];

			docSrc dsrc;
			if( connected == "and" ) {
				set_intersection( ALL( dSrc1 ), ALL( dSrc2 ), INS( dsrc ) );
			} else {
				set_union( ALL( dSrc1 ), ALL( dSrc2 ), INS( dsrc ) );
			}

			WordsToFigure( src, dsrc, w1, w2 );
		} else {
			stringstream ss( command );
			string w1;
			ss >> w1 >> w1;
			NotWord( w1, src );
		}
		PrintSrc( src );
	}
	return 0;
}

void Standard( string &line ) {
	int length = line.length();
	for( int i=0; i<length; i++ ) {
		if( isalpha( line[i] ) ) {
			line[i] = tolower( line[i] ); 
		} else {
			line[i] = ' ';
		}
	}
}

void WordRecord( string &line, int docOrder, int lineOrder ) {
	stringstream ss( line );
	string word;
	while( ss >> word ) {
		if( dict.count( word ) ) { 
			if( !dict[word].count( Figure( docOrder, lineOrder ) ) ) { 
				dict[word].insert( Figure( docOrder, lineOrder ) ) ;
			}
		} else {
			Src src;
			src.insert( Figure( docOrder, lineOrder ) );
			dict[ word ] = src;
		}
		if( docMap.count( word ) ) {
			docMap[word].insert( docOrder );
		} else {
			docSrc ds;
			docMap[word] = ds;
			docMap[word].insert( docOrder );
		}
	}
}

void PrintSrc( Src &src ) { 
	if( src.size() == 0 ) {
		printf("Sorry, I found nothing.\n");
		printf( "==========\n" );
		return ;
	}
	Src :: iterator it = src.begin(), bef;
	printf( "%s\n", wordLine[ *it ].c_str() );
	bef = it++;
	while( it != src.end() ) {
		if( it->docOrder != bef->docOrder ) {
			printf( "----------\n" );
		}
		printf( "%s\n", wordLine[ *it ].c_str() );
		bef = it;
		it ++;
	}
	printf( "==========\n" );
}

void WordsToFigure( Src &src, docSrc &dsrc, string& w1, string& w2 ) {
	docSrc :: iterator it;
	for( it=dsrc.begin(); it != dsrc.end(); it ++ ) {
		Src :: iterator it2 ;
		for( it2 = dict[ w1 ].begin(); it2 !=dict[w1].end(); it2 ++ ) {
			if( *it == it2 -> docOrder ) {
				src.insert( *it2 );
			}
		}
		for( it2 = dict[ w2 ].begin(); it2 !=dict[w2].end(); it2 ++ ) {
			if( *it == it2 -> docOrder ) {
				src.insert( *it2 );
			}
		}
	}
}

void NotWord( string& word, Src &src ) { 
	docSrc dsrc = docMap[ word ];
	vector< Doc > :: iterator it;
	for( it = docs.begin(); it != docs.end(); it ++ ) {
		if( !dsrc.count( it->docOrder ) ) {
			for( int i=0; i< it->lineLimit; i ++ ) {
				src.insert( Figure( it->docOrder, i ) );
			}
		}
	}
}



