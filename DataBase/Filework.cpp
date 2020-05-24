 #include "Filework.h"

int Filework::DB_open(phrases* Sp) {
	uint16_t CheckPIN(0);
		DB.exceptions(ifstream::badbit | ifstream::failbit);
		cout << Sp->DBname_ivite() << endl;
		while (!DB.is_open()) {
			cout << " > ";
			getline(cin, DB_name);
			if (DB_name.empty()) {
				cout << Sp->EmptyErr() << endl;
				continue;
			}
			if (DB_name == "!Q") return 0;
			try
			{
				cout << Sp->Ftry() << endl;
				DB.open(DB_name, ios::in | ios::out | ios::binary);
				cout << Sp->Fope() << endl;
			}
			catch (const ifstream::failure& ex)
			{
				cout << ex.what() << endl;
				cout << ex.code() << endl;
				cout << Sp->Ferr() << endl;
				continue;
			}
			if (DB.peek() == EOF) {
				cout << Sp->Femp() << endl;
				DB.close();
				continue;
			}
			CheckPIN |= DB.get() << 8;
			CheckPIN |= DB.get();
			if (CheckPIN != 0x0573) {
				cout << Sp->FnDB() << endl;
				DB.close();
			}
		}
		size_t PointPos = DB_name.length();
		int32_t SlashPos = -1;
		for (uint32_t i = 0; i < DB_name.length(); i++) {
			if (DB_name[i] == '.') PointPos = i;
			if (DB_name[i] == '\\') SlashPos = i;
		}
		for (int32_t i = SlashPos + 1; i < PointPos; i++) {
			DB_short_name += DB_name[i];
		}
	return 1;
}

int Filework::DB_create(phrases* Sp) {
	DB.exceptions(ifstream::badbit | ifstream::failbit);
	system("cls");
	cout << Sp->DBname_ivite() << endl;
	while (!DB.is_open()) {
		getline(cin, DB_name);
		if (DB_name == "!Q") return 0;
		try
		{
			cout << Sp->Ftry() << endl;
			DB.open(DB_name + ".sdb", ios::in | ios::binary);
			cout << Sp->FceateErr() << endl;
			DB.close();
			continue;
		}
		catch (const ifstream::failure&)
		{
			DB.open(DB_name + ".sdb", ios::out | ios::binary);
			DB.close();
			DB.open(DB_name + ".sdb", ios::in | ios::out | ios::binary);
			cout << Sp->Fope() << endl;
		}
	}
	size_t PointPos = DB_name.length();
	int32_t SlashPos = -1;
	for (uint32_t i = 0; i < DB_name.length(); i++) {
		if (DB_name[i] == '.') PointPos = i;
		if (DB_name[i] == '\\') SlashPos = i;
	}
	DB << (char)0x05 << (char)0x73;
	for (int32_t i = SlashPos + 1; i < PointPos; i++) {
		DB_short_name += DB_name[i];
		DB << DB_name[i];
	}
	DB.exceptions(ifstream::goodbit);
	return 1;
}