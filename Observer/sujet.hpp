#ifndef SUBJECT
#define SUBJECT

class Observer;

class Subject{

	public:
		Subject();
		virtual ~Subject();
		virtual void addObserver(Observer o) = 0;
		virtual void removeobserver(Observer o) = 0;
		virtual void notifyObserver() =0;


};

#endif