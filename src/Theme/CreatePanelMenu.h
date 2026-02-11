//Thank you Count Modula for your eminently readable code.
//It would've been much harder for me without your repository,
//and your trick with the includes is fabulous.


menu->addChild(createMenuLabel("Panel"));

//create named shell for list of panel options
PanelMenu* menulist = createMenuItem<PanelMenu>("Choose Panel", RIGHT_ARROW);
menulist->module = module;
menu->addChild(menulist);
