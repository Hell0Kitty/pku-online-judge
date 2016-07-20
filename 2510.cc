#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<double> queries;

class cSubstance
{
public:
	cSubstance( int type, double time, double n )
		: _type( type ), _time( time ), _n( n )
	{}

	~cSubstance()
	{}

	double getEffect( double t )
	{
		if( t < _time ) 
			return 0;

		double ret = 0;
		if( _type == 1 )
			ret = 8.0*_n-(t-_time)/12.0;
		else 
			ret = 2.0*_n-(t-_time)*(t-_time)/79.0;

		if( ret < 0 )
			ret = 0;

		return ret;
	}

	double _time;
	double _n;
	int _type;
};

cSubstance *subs[100];
int nsubs;

int main()
{
	char buff[255];

	while( cin.getline( buff, 255 ) )
	{

		if( buff[0] == 'Q' )
		{
			double time;
			sscanf( buff+5, "%lf", &time );
			queries.push_back( time );

			continue;
		}

		char stype[25];
		double time;
		double n;
		sscanf( buff, "%s %lf %lf", stype, &time, &n );
		subs[ nsubs++ ] = new cSubstance( (string( "Coffee" ) == stype ? 0 : 1 ), 
			time, n );
	}

	sort( queries.begin(), queries.end() );

	for( int i=0; i<queries.size(); i++ )
	{
		double total = 0;
		for( int j=0; j<nsubs; j++ )
			total += subs[j]->getEffect( queries[i] );
		if( total < 1 )
			total = 1;

		printf( "%d %.1f\n", int(queries[i]), total );
	}

	for( int i=0; i<nsubs; i++ )
		delete subs[i];

	return 0;
}



