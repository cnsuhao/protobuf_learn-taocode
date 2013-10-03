#include <stdio.h>
#include <string.h>
#include "test.pb.h"

using namespace std;
using namespace hello;

int main()
{
	Hello a;
	a.set_id(101);
	a.set_name("xg");
	string tmp;
	bool ret = a.SerializeToString(&tmp);
	if (ret)
	{
		printf("encode success!\n");
	}
	else
	{
		printf("encode faild!\n");
	}

	Hello b;
	ret = b.ParseFromString(tmp);
	if (ret)
	{
		printf("decode success!\n id= %d \n name = %s\n", b.id(), b.name().c_str());
	}
	else
	{
		printf("decode faild!\n");
	}
	return 0;
}
