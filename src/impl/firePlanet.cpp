#include "firePlanet.h"

FirePlanet::FirePlanet(string name) : Planet(name, Direction::B, "the spaceship, looking invitingly cool compared to the temperature out here.")
{
    crater = new Location("10", "The spaceship sits behind you, hanging on the edge of a large crater, which glows mysteriously due to the magma inside.");
    ship_item = new Item(true, "The spaceship is still there, thank goodness.", "The plating on the bottom looks a little blackened after the descent through the hot atmosphere.");
    ship_item->addName("ship"); ship_item->addName("spaceship"); ship_item->addName("spacecraft");
    crater_item = new Item(true, "The crater behind the spaceship glows ominously.", "It looks pretty deep. The bottom, far below you, has what looks like a lava spring filling it. You wish you'd spotted a better patch of ground to land on, but this was the closest place to the evidence of life you spotted from the air. It'll do for now.");
    crater_item->addName("crater");
    sign1 = new Sign("A metal board attached to a section of small girder protrudes from the ground. You guess that this is the Paxak version of signs.", "src/signs/firePlanet/sign1.txt");
    crater->addItem(ship_item); crater->addItem(crater_item); crater->addItem(sign1);

    volcano_base = new Location("11", "You look up at the peak of the smoking volcano to your left. You decide not to risk your life venturing up.");
    volcano = new Item(true, "The volcano stands there like a lightly sleeping giant.", "You reason that going to the top would be a pretty quick way to end your life.");
    volcano->addName("mountain"); volcano->addName("volcano");
    sign2 = new Sign("Facing away from the volcano is a second sign, almost red hot from the heated ground.", "src/signs/firePlanet/sign2.txt");
    volcano_base->addItem(volcano); volcano_base->addItem(sign2);

    mine = new Location("12", "In front of you is a dark entrance cut into the side of a mountain. Judging by the pickaxe like tools lying nearby, this may have been a mine.");
    mine_item = new Item(true, "The forbidding entrance makes you feel uneasy", "The more you look into the hole, the more you get the feeling something might be looking back.");
    mine_item->addName("mine"); mine_item->addName("entrance");
    sign3 = new Sign("Another sign is propped up against the entrance.", "src/signs/firePlanet/sign3.txt");
    mine->addItem(mine_item); mine->addItem(sign3);

    village = new Location("13", "You are surrounded by tumbledown houses, broken and split. Debris is strewn from the doorways, as if they were hurriedly deserted.");
    buildings = new Item(true, "The houses appear to be glittering slightly in the light of the everpresent lava.", "The houses appear to have been made from a glass like substance, now shattered. It's terrible, but it's also beautiful.");
    buildings->addName("buildings"); buildings->addName("houses");
    sign4 = new Sign("Just outside the village is another sign, telling more of the story.", "src/signs/firePlanet/sign4.txt");
    village->addItem(buildings); village->addItem(sign4);

    lava_pool = new Location("14", "You go as close to the lava pool as you dare. It is hot.");
    pool = new Item(true, "The pool of lava is constantly in motion, as if being stirred from within.", "The heat of the molten rock is making bubbles in the liquid, and whenever they burst you have to be careful not to get burned.");
    pool->addName("pool"); pool->addName("lava");
    sign5 = new Sign("In danger of being consumed by the spitting lava is another sign.", "src/signs/firePlanet/sign5.txt");
    lava_pool->addItem(pool); lava_pool->addItem(sign5);

    workshop = new Location("15", "The building is the least damaged of all the ones you have seen here, but then it's not made of the same material as the others.");
    forge = new Item(true, "The small building looks solid and heavily fireproofed, and as if it has had to be rebuilt multiple times.", "The substance the building is made of reminds you of the hardened black rocks you have seen floating within the lava. Inside the building you see a furnace, an anvil, and an iron bucket filled with tools of a blacksmith. This must be the workshop of Paxak.");
    forge->addName("forge"); forge->addName("workshop"); forge->addName("building");
    sign6 = new Sign("Stuck on the door is the sign that completes the story.", "src/signs/firePlanet/sign6.txt");
    workshop->addItem(forge); workshop->addItem(sign6);

    addLocation(crater); addLocation(volcano_base); addLocation(mine); addLocation(village); addLocation(lava_pool); addLocation(workshop);
    setLandingLocation(0);

    crater->setPath(Direction::L, volcano_base, "a rocky path leading towards a large smoking vlcano in the distance.");
    volcano_base->setPath(Direction::R, crater, "the path leading back to the crater where you left your ship.");
    volcano_base->setPath(Direction::F, mine, "a well worn path that goes as far as the next mountain.");
    mine->setPath(Direction::B, volcano_base, "the path leading back towards the volcano.");
    mine->setPath(Direction::R, village, "a steep path up the side of a hill.");
    village->setPath(Direction::L, mine, "the mine at the bottom of the hill.");
    village->setPath(Direction::B, crater, "the strange contraption that will allow you to descend the cliff and return to your ship.");
    village->setPath(Direction::R, lava_pool, "large pools of lava, one of which has a sign at its edge.");
    lava_pool->setPath(Direction::L, village, "the village, right at the top of the hill.");
    lava_pool->setPath(Direction::B, workshop, "a rather isolated little building, and what looks like a rudimentary railway.");
    workshop->setPath(Direction::F, lava_pool, "the pools of lava.");
    workshop->setPath(Direction::L, crater, "the simple railway set up to take you back towards the crater where you left your ship.");
}

FirePlanet::~FirePlanet()
{
    delete crater;
    delete ship_item;
    delete crater_item;
    delete sign1;
    delete volcano_base;
    delete volcano;
    delete sign2;
    delete mine;
    delete mine_item;
    delete sign3;
    delete village;
    delete buildings;
    delete sign4;
    delete lava_pool;
    delete pool;
    delete sign5;
    delete workshop;
    delete forge;
    delete sign6;
}
