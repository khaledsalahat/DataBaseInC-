#include<iostream>
#include<cstring>

using namespace std;

struct STUDENT {
	char name[64];
	char addr[64];
	char major[64];
	int id;
	int age;
	int level;
	STUDENT* next_student = NULL;
};

struct LEVELS {
	int id;
	int level;
	STUDENT* head_student = NULL;
	LEVELS* next_level = NULL;
};

STUDENT* head = NULL;
LEVELS* levels = NULL;
void set_name(int id, char name[]) {
	STUDENT* p = head;
	while (p != NULL) {
		if (p->id == id) {
			strcpy_s(p->name, name);
			return;
		}
		p = p->next_student;
	}
	LEVELS* g = levels;
	while (g != NULL) {
		p = g->head_student;
		while (p != NULL) {
			if (p->id == id) {
				strcpy_s(p->name, name);
				return;
			}
		}
	}
	cout << "No match"<<endl;
	
}

void ListLevels() {
	LEVELS* p = levels;
	while (p != NULL) {
		if (p->head_student == NULL) {
			p = p->next_level;
			continue;
		}
		cout << p->level << " ";
		p = p->next_level;
	}
	cout << endl;
}
void add(int id) {
	STUDENT* newstudent=new STUDENT;
	newstudent->id = id;
	STUDENT* p = head;
	if (head == NULL) {
		head = newstudent;
		return;
	}
	while (p->next_student != NULL)
		p = p->next_student;
	p->next_student = newstudent;

}

void pr() {
	STUDENT* p = head;
	while (p != NULL) {
		cout << p->id << " " << p->name << endl;
		p = p->next_student;
	}
}
void set_addr(int id, char addr[]) {
	STUDENT* p = head;
	while (p != NULL) {
		if (p->id == id) {
			strcpy_s(p->addr, addr);
			return;
		}
		p = p->next_student;
	}
	LEVELS* g = levels;
	while (g != NULL) {
		p = g->head_student;
		while (p != NULL) {
			if (p->id == id) {
				strcpy_s(p->addr, addr);
				return;
			}
		}
	}
	cout << "No match" << endl;
}
void set_major(int id, char major[]) {
	STUDENT* p = head;
	while (p != NULL) {
		if (p->id == id) {
			strcpy_s(p->major, major);
			return;
		}
		p = p->next_student;
	}
	LEVELS* g = levels;
	while (g != NULL) {
		p = g->head_student;
		while (p != NULL) {
			if (p->id == id) {
				strcpy_s(p->major, major);
				return;
			}
		}
	}
	cout << "No match" << endl;
}
void set_age(int id, int age) {
	STUDENT* p = head;
	while (p != NULL) {
		if (p->id == id) {
			p->age = age;
			return;
		}
		p = p->next_student;
	}
	LEVELS* g = levels;
	while (g != NULL) {
		p = g->head_student;
		while (p != NULL) {
			if (p->id == id) {
				p->age = age;
				return;
			}
		}
	}
	cout << "No match" << endl;
}
void set_level(int id, int level) {
	STUDENT* p = head;
	STUDENT* d = head;
	while (p != NULL) {
		if (p->id == id) {
			LEVELS* newlevel = new LEVELS;
			newlevel->level = level;
			LEVELS* w = levels;
			LEVELS* ww = w;
			if (levels == NULL) {
				levels = newlevel;
				levels->head_student = p;
				d->next_student = p->next_student;
				if (p == d) {
					head = head->next_student;
				}
				p->next_student = NULL;
				p->level = level;
				return;
			}
			while (w != NULL) {
				if (w->level == level) {
					STUDENT* f = w->head_student;
					if (f == NULL) {
						w->head_student = p;
						d->next_student = p->next_student;
						if (p == d) {
							head = head->next_student;
						}
						p->next_student = NULL;
						p->level = level;
						return;
					}
					while (f->next_student != NULL) {
						f = f->next_student;
					}
					f->next_student = p;
					d->next_student = p->next_student;
					if (p == d) {
						head = head->next_student;
					}
					p->next_student = NULL;
					p->level = level;
					return;
				}
				ww = w;
				w = w->next_level;

			}
			ww->next_level = newlevel;
			ww->next_level->head_student = p;
			d->next_student = p->next_student;
			if (p == d) {
				head = head->next_student;
			}
			p->next_student = NULL;
			p->level = level;
			return;
		}
		d = p;
		p = p->next_student;
	}
	LEVELS* g = levels;
	while (g != NULL) {
		STUDENT* v = g->head_student;
		STUDENT* l = v;
		while (v != NULL) {
			if (v->id == id) {
				LEVELS* w = levels;
				LEVELS* ww = w;
				while (w != NULL) {
					if (w->level == level) {					
						STUDENT* k = w->head_student;
						if(k == NULL){
							w->head_student = v;
							l->next_student = v->next_student;
							if (l == v) {
								g->head_student = g->head_student->next_student;
							}
							v->next_student = NULL;
							v->level = level;
							return;
						}
						while (k->next_student != NULL) {
							k = k->next_student;
						}
						k->next_student = v;
						l->next_student = v->next_student;
						if (l == v) {
							g->head_student = g->head_student->next_student;
						}
						v->next_student = NULL;
						v->level = level;
						return;
					}
					ww = w;
					w = w->next_level;
				}
				ww->next_level = new LEVELS;
				ww->next_level->level = level;
				ww->next_level->head_student = v;
				l->next_student = v->next_student;
				if (l == v) {
					g->head_student = g->head_student->next_student;
				}
				v->next_student = NULL;
				v->level = level;
				return;
			}
			l = v;
			v = v->next_student;
		}
		g = g->next_level;
	}
	cout << "NO match" << endl;


}
void list_in_level(int level) {
	LEVELS* p = levels;
	while (p != NULL) {
		if (p->level == level) {
			STUDENT* v = p->head_student;
			while (v != NULL) {
				cout << v->id << " " << v->name << " " << v->addr << " " << v->major << " " << v->age << " " << v->level << endl;
				v = v->next_student;
			}
			return;
		}
		p = p->next_level;
	}
	cout << "NO match" << endl;
}

void importFile(char fileName[]) {
	FILE* f;
	errno_t err = fopen_s(&f, fileName, "r");
	if (err) {
		cout << "Filed to open file" << endl;
		return;
	}
	int id, age, level;
	char name[64];
	char addr[64];
	char major[64];
	while (fscanf_s(f, "%d %s %s %s %d %d", &id, name, _countof(name), addr, _countof(addr), major, _countof(major), &age, &level) != EOF) {
		add(id);
		set_name(id, name);
		set_addr(id, addr);
		set_major(id, major);
		set_age(id, age);
		set_level(id, level);
	}
	fclose(f);
}

void SaveFile(char fileName[]) {
	FILE* f;
	fopen_s(&f, fileName, "w+");
	LEVELS* p = levels;
	while (p != NULL) {
		STUDENT* s = p->head_student;
		while (s != NULL) {
			fprintf_s(f, "%d %s %s %s %d %d\n", s->id, s->name, s->addr, s->major, s->age, s->level);
			s = s->next_student;
		}
		p = p->next_level;
	}
	fclose(f);
}

void printAll() {
	LEVELS* p = levels;
	while (p != NULL) {
		STUDENT* s = p->head_student;
		while (s != NULL) {
			printf_s("%d %s %s %s %d %d\n", s->id, s->name, s->addr, s->major, s->age, s->level);
			s = s->next_student;
		}
		p = p->next_level;
	}
}

void Delete(int id) {
	LEVELS* p = levels;
	while (p != NULL) {
		STUDENT* s = p->head_student;
		STUDENT* ss = s;
		while (s != NULL) {
			if (s->id == id) {
				ss->next_student = s->next_student;
				if (ss == s) {
					p->head_student = p->head_student->next_student;
				}
				s->next_student = NULL;
				cout << "Deleted student with id " << s->id << endl;
				delete s;
				return;
			}
			ss = s;
			s = s->next_student;
		}
		p = p->next_level;
	}
	cout << "NO match" << endl;
}
int main() {
	char cmd[100];
	bool ext = false;
	
	while (!ext) {
		cin >> cmd;
		if (strcmp(cmd, "Exit") == 0) {
			ext = 1;
		}
		else if (strcmp(cmd, "List_in_level") == 0) {
			int level;
			cin >> level;
			list_in_level(level);
		}
		else if (strcmp(cmd, "ListLevels") == 0) {
			ListLevels();
		}
		else if (strcmp(cmd, "ImportFile") == 0) {
			char arg1[100];
			cin >> arg1;
			importFile(arg1);
		}
		else if (strcmp(cmd, "SaveFile") == 0) {
			char arg1[100];
			cin >> arg1;
			SaveFile(arg1);
		}
		else if (strcmp(cmd, "Add") == 0) {
			int id;
			cin >> id;
			add(id);
		}
		else if (strcmp(cmd, "Set_name") == 0) {
			int id;
			char name[10];
			cin >> id >> name;
			set_name(id, name);
		}
		else if (strcmp(cmd, "Set_addr") == 0) {
			int id;
			char addr[10];
			cin >> id >> addr;
			set_addr(id, addr);
		}
		else if (strcmp(cmd, "Set_major") == 0) {
			int id;
			char major[10];
			cin >> id >> major;
			set_major(id, major);
		}
		else if (strcmp(cmd, "Set_age") == 0) {
			int id;
			int age;
			cin >> id >> age ;
			set_age(id, age);
		}
		else if (strcmp(cmd, "Set_level") == 0) {
			int id;
			int level;
			cin >> id >> level;
			set_level(id, level);
		}
		else if (strcmp(cmd, "p") == 0) {
			pr();
		}
		else if (strcmp(cmd, "printAll") == 0) {
			printAll();
		}
		else if (strcmp(cmd, "Delete") == 0) {
			int id;
			cin >> id;
			Delete(id);
		}
		else {
			cout << "Command doesn't exist\n";
		}
	
	}
	return 0;
}