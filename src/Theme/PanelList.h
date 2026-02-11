struct ListItem : MenuItem {
	MODULE_NAME* module;
	int Panel = 0;

	void onAction(const event::Action& e) override {
		module->currPanel = Panel;
	}
};


struct PanelMenu : MenuItem {
	MODULE_NAME* module;

	Menu* createChildMenu() override {
		Menu* menu = new Menu;

		ListItem* OriginalMenuItem = createMenuItem<ListItem>("Dark", CHECKMARK(module->currPanel == 0));
		OriginalMenuItem->module = module;
		OriginalMenuItem->Panel = 0;
		menu->addChild(OriginalMenuItem);


		ListItem* BlueMenuItem = createMenuItem<ListItem>("Blue Night", CHECKMARK(module->currPanel == 1));
		BlueMenuItem->module = module;
		BlueMenuItem->Panel = 1;
		menu->addChild(BlueMenuItem);


		ListItem* PurpleMenuItem = createMenuItem<ListItem>("Purple Jewel", CHECKMARK(module->currPanel == 2));
		PurpleMenuItem->module = module;
		PurpleMenuItem->Panel = 2;
		menu->addChild(PurpleMenuItem);

		ListItem* RedMenuItem = createMenuItem<ListItem>("Red Ruby", CHECKMARK(module->currPanel == 3));
		RedMenuItem->module = module;
		RedMenuItem->Panel = 3;
		menu->addChild(RedMenuItem);

		ListItem* WhiteMenuItem = createMenuItem<ListItem>("White", CHECKMARK(module->currPanel == 4));
		WhiteMenuItem->module = module;
		WhiteMenuItem->Panel = 4;
		menu->addChild(WhiteMenuItem);

		ListItem* SoulMenuItem = createMenuItem<ListItem>("Soulless", CHECKMARK(module->currPanel == 5));
		SoulMenuItem->module = module;
		SoulMenuItem->Panel = 5;
		menu->addChild(SoulMenuItem);

		return menu;
	}
};