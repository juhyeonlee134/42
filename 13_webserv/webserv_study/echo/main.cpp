#include "Connection.hpp"
#include <stdio.h>
#include <iostream>

int main(void)
{
	try
	{
		Connection connection;
		while (1)
		{
			connection.echo();
		}
	}
	catch(std::runtime_error const & e)
	{
		perror(e.what());
	}
	catch(std::logic_error const & e)
	{
		std::cerr << e.what() << '\n';
		exit(1);
	}
	return 0;
}
