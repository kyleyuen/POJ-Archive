#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
//#include <vector>
#include <stack>
#include <utility>
#include <map>

using namespace std;

//函数声明
string encode( const string &msg, stack<int> &decode_msg );
string decode( const string &encode_str, stack<int> &decode_msg );
int code_len( char c );

//main
int main( void ) {
	int n;
	cin >> n;

	for ( int i = 0; i < n; ++i ) {
		string msg, encode_str;
		//vector<int> decode_msg;
		stack<int> decode_msg;
		cin >> msg;
		encode_str = encode( msg, decode_msg );
		cout << i + 1 << ": "
		     << decode( encode_str, decode_msg )
		     << endl;
	}

	return 0;
}

string encode( const string &msg, stack<int> &decode_msg ) {
	string encode_str;
	map< char, string > encode_map;
	encode_map.insert( make_pair( 'A', ".-" ) );
	encode_map.insert( make_pair( 'B', "-..." ) );
	encode_map.insert( make_pair( 'C', "-.-." ) );
	encode_map.insert( make_pair( 'D', "-.." ) );
	encode_map.insert( make_pair( 'E', "." ) );
	encode_map.insert( make_pair( 'F', "..-." ) );
	encode_map.insert( make_pair( 'G', "--." ) );
	encode_map.insert( make_pair( 'H', "...." ) );
	encode_map.insert( make_pair( 'I', ".." ) );
	encode_map.insert( make_pair( 'J', ".---" ) );
	encode_map.insert( make_pair( 'K', "-.-" ) );
	encode_map.insert( make_pair( 'L', ".-.." ) );
	encode_map.insert( make_pair( 'M', "--" ) );
	encode_map.insert( make_pair( 'N', "-." ) );
	encode_map.insert( make_pair( 'O', "---" ) );
	encode_map.insert( make_pair( 'P', ".--." ) );
	encode_map.insert( make_pair( 'Q', "--.-" ) );
	encode_map.insert( make_pair( 'R', ".-." ) );
	encode_map.insert( make_pair( 'S', "..." ) );
	encode_map.insert( make_pair( 'T', "-" ) );
	encode_map.insert( make_pair( 'U', "..-" ) );
	encode_map.insert( make_pair( 'V', "...-" ) );
	encode_map.insert( make_pair( 'W', ".--" ) );
	encode_map.insert( make_pair( 'X', "-..-" ) );
	encode_map.insert( make_pair( 'Y', "-.--" ) );
	encode_map.insert( make_pair( 'Z', "--.." ) );
	encode_map.insert( make_pair( ',', ".-.-" ) );
	encode_map.insert( make_pair( '.', "---." ) );
	encode_map.insert( make_pair( '_', "..--" ) );
	encode_map.insert( make_pair( '?', "----" ) );

	for ( string::const_iterator itr = msg.begin(); itr != msg.end(); ++itr ) {
		stringstream ss;
		int tmp;
		decode_msg.push( code_len( *itr ) );
		map<char, string>::iterator it = encode_map.find( *itr );

		if ( it != encode_map.end() ) {
			encode_str += it->second;
		} //no throw
	}

	return encode_str;
}

string decode( const string &encode_str, stack<int> &decode_msg ) {
	string decode_str;
	string::size_type offset = 0;
	map<string, char> decode_map;
	decode_map.insert( make_pair( ".-", 'A' ) );
	decode_map.insert( make_pair( "-...", 'B' ) );
	decode_map.insert( make_pair( "-.-.", 'C' ) );
	decode_map.insert( make_pair( "-..", 'D' ) );
	decode_map.insert( make_pair( ".", 'E' ) );
	decode_map.insert( make_pair( "..-.", 'F' ) );
	decode_map.insert( make_pair( "--.", 'G' ) );
	decode_map.insert( make_pair( "....", 'H' ) );
	decode_map.insert( make_pair( "..", 'I' ) );
	decode_map.insert( make_pair( ".---", 'J' ) );
	decode_map.insert( make_pair( "-.-", 'K' ) );
	decode_map.insert( make_pair( ".-..", 'L' ) );
	decode_map.insert( make_pair( "--", 'M' ) );
	decode_map.insert( make_pair( "-.", 'N' ) );
	decode_map.insert( make_pair( "---", 'O' ) );
	decode_map.insert( make_pair( ".--.", 'P' ) );
	decode_map.insert( make_pair( "--.-", 'Q' ) );
	decode_map.insert( make_pair( ".-.", 'R' ) );
	decode_map.insert( make_pair( "...", 'S' ) );
	decode_map.insert( make_pair( "-", 'T' ) );
	decode_map.insert( make_pair( "..-", 'U' ) );
	decode_map.insert( make_pair( "...-", 'V' ) );
	decode_map.insert( make_pair( ".--", 'W' ) );
	decode_map.insert( make_pair( "-..-", 'X' ) );
	decode_map.insert( make_pair( "-.--", 'Y' ) );
	decode_map.insert( make_pair( "--..", 'Z' ) );
	decode_map.insert( make_pair( ".-.-", ',' ) );
	decode_map.insert( make_pair( "---.", '.' ) );
	decode_map.insert( make_pair( "..--", '_' ) );
	decode_map.insert( make_pair( "----", '?' ) );

	while ( !decode_msg.empty() ) {
		string tran;
		map<string, char>::iterator it;
		int n = decode_msg.top();
		decode_msg.pop();
		tran = encode_str.substr( offset, n );
		offset += n;
		it = decode_map.find( tran );

		if ( it != decode_map.end() ) {
			decode_str += it->second;
		}
	}

	return decode_str;
}

int code_len( char c ) {
	switch ( c ) {
		case 'E':
		case 'T':
			return 1;
		case 'A':
		case 'I':
		case 'M':
		case 'N':
			return 2;
		case 'D':
		case 'G':
		case 'K':
		case 'O':
		case 'R':
		case 'S':
		case 'U':
		case 'W':
			return 3;
		case 'B':
		case 'C':
		case 'F':
		case 'H':
		case 'J':
		case 'L':
		case 'P':
		case 'Q':
		case 'V':
		case 'X':
		case 'Y':
		case 'Z':
		case ',':
		case '.':
		case '_':
		case '?':
			return 4;
	}
}
