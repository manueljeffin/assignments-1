struct Reference{
	char * contact_person_id;
	char * first_name;
	char * last_name;
	char * email;	
};

struct Person{
	char * contact_id;
	char * contact_name;
	char * street;
	char * area;
	char * city;
	struct Reference * contact_persons;	
} * persons;
