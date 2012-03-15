//#include <boost/lambda/lambda.hpp
#include <iostream>
using namespace std;
#include <iterator>
#include <algorithm>
#include <boost/thread.hpp>
#include <pthread.h>
#include <signal.h>
#include "../inc.h"

class teste {
	public:
	float myball;
	teste() {
		myball = 0;
	};
	void increase() {
		myball++;
	}
};

int tmp = 0;
char lixo = 'a';

void *counter(void* aGent) {
	//while(1) tmp++;
	teste *tmp = (teste*)aGent;
	cout << "Myball: " << tmp->myball << endl;
	tmp->increase();
	while(1);
}

void killThread(int sig) {
	pthread_exit(0);
}

int main()
{
	(void) signal(SIGUSR1,killThread);
  /*  using namespace boost::lambda;
    typedef std::istream_iterator<int> in;

    std::for_each(
        in(std::cin), in(), std::cout << (_1 * 3) << " " );*/
	teste *testeT = new teste();
        cout << "ok" << endl;
//        boost::thread teste(&hello);
	pthread_t carrier,passengers[5];
	pthread_create(&passengers[0],NULL,counter,testeT);
	time_t start,end;
	cout << "It has begun!" << clock() << endl;
	time(&start);
	time(&end);
	while(difftime(end,start) <= 5) time(&end);
	cout << "It has ended!" << clock() << endl;

	cout << "Passou!" << endl;
    pthread_kill(passengers[0],SIGUSR1);
	cout << "Myball: " << testeT->myball << endl;

}

