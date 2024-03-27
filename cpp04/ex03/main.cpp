#include <iostream>

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int testcase_niko(void)
{
	std::cout << "\n\t---FromSubject---\n" << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << "\n\t---Extra---\n" << std::endl;

	me->equip(NULL);
	me->use(2, *bob);

	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);
	me->unequip(3745989);

	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->unequip(0);
	me->unequip(1);
	me->unequip(2);
	me->unequip(3);

	delete src;
	src = new MateriaSource();

	tmp = src->createMateria("ice");
	src->learnMateria(new Ice());
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	tmp = src->createMateria("blah");

	ICharacter* copy = new Character(*static_cast<Character *>(me));
	delete me;

	IMateriaSource* matcopy = new MateriaSource(*static_cast<MateriaSource *>(src));
	delete src;

	tmp = matcopy->createMateria("lllll");
	tmp = matcopy->createMateria("ice");
	copy->equip(tmp);
	copy->use(0, *bob);
	copy->use(1, *bob);
	copy->unequip(2);

	IMateriaSource* cpyasign = new MateriaSource();
	*static_cast<MateriaSource *>(cpyasign) = *static_cast<MateriaSource *>(matcopy);
	delete matcopy;

	copy->equip(cpyasign->createMateria("ice"));

	delete bob;
	delete copy;
	delete cpyasign;
	return 0;
}

void testcase_felix()
{
    IMateriaSource *src = new MateriaSource();
    ICharacter *dest = new Character();

    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(NULL); 
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    src->learnMateria(new Cure());
    
    dest->equip(src->createMateria("ice")); //Valid
    dest->equip(src->createMateria("Ice")); //Invalid
    dest->equip(src->createMateria("hot")); //Invalid!!
    dest->equip(src->createMateria("cure")); //Valid
    dest->equip(src->createMateria("ice")); //Valid
    dest->equip(src->createMateria("cure")); //Valid
    dest->equip(src->createMateria("ice")); //Valid -> Overflow!

    dest->unequip(3);

    dest->equip(src->createMateria("cure")); //Equiped idx 3;
    
    dest->unequip(0);

    dest->equip(src->createMateria("ice")); //Equiped idx 0; 

    dest->unequip(9);

    ICharacter *flori = new Character("Flori");
    ICharacter *nicooo = new Character("Nicooo"); 


    dest->use(0, *flori); // ice
    dest->use(1, *nicooo); // cure

    delete src;
    delete dest;
	delete flori;
	delete nicooo;
}

void	testcase_florian(void)
{
	IMateriaSource* src1 = new MateriaSource();
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());
    src1->learnMateria(NULL);

    IMateriaSource* src2 = new MateriaSource();
    src1->learnMateria(new Ice());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Cure());
    src1->learnMateria(new Cure());

    *static_cast<MateriaSource *>(src2) = *static_cast<MateriaSource *>(src1);

    ICharacter  *p1 = new Character("player 1");
    std::cout << "Name of p1: '" << p1->getName() << "'" << std::endl;

    p1->unequip(-1);
    p1->unequip(0);
    p1->unequip(4);

    AMateria*   ice = src1->createMateria("ice");
    AMateria*   cure = src1->createMateria("cure");

    AMateria*   ice_wrong = src1->createMateria("Ice");
    AMateria*   cure_wrong = src1->createMateria("Cure");

    if (ice_wrong != NULL || cure_wrong != NULL)
        std::cout << "ERROR" << std::endl;

    p1->use(-1, *p1);
    p1->use(0, *p1);
    p1->use(4, *p1);

    p1->equip(NULL);
    p1->equip(ice);
    p1->equip(cure);

    p1->use(0, *p1); //ice at player1
    p1->use(1, *p1); //cure at player1

    ICharacter  *p2 = new Character("player 2");
    std::cout << "\nName of p2: '" << p2->getName() << "'" << std::endl;

    p2->use(-1, *p2);
    p2->use(0, *p2);
    p2->use(4, *p2);

    AMateria*   cure_2 = src1->createMateria("cure");

    p2->equip(cure_2);

    p2->use(0, *p2); //ice at player2

    *static_cast<Character *>(p2) = *static_cast<Character *>(p1);

    ICharacter  *p3 = new Character("player 3");

    p2->use(0, *p2); //ice at player2
    p2->use(1, *p3); //cure at player3
    p2->use(2, *p2);

    delete (p1);
    delete (p2);
    delete (p3);

    delete (src1);
    delete (src2);
}

int main(void)
{
	std::cout << "\n===TestCaseFelix===\n" << std::endl;
	testcase_felix();
	std::cout << "\n===TestCaseFlorian===\n" << std::endl;
	testcase_florian();
	std::cout << "\n===TestCaseNiko===\n" << std::endl;
	testcase_niko();
	Ground::cleanGround();
}
