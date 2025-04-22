#include"Menu.h"
//hàm so sánh max, giá trị nào lớn nhất thì trả về giá trị đó
  inline int MENU:: MAX()const {
	if (dispCnt > soundCnt) {
		if (dispCnt > generalCnt) {
			return dispCnt;
		}
		else return generalCnt;
	}
	if (dispCnt == soundCnt) {
		if (dispCnt > generalCnt) {
			return dispCnt;
		}
		else return generalCnt;
	}
	else {
		if (soundCnt > generalCnt) {
			return soundCnt;
		}
		else return generalCnt;
	}
  }
  //thao tác file, ghi dữ liệu vào file
  void MENU:: filesetting() {
	  fstream settingFile("Setting.txt", ios_base::out);

	  if (!settingFile) {
		  std::cerr << "Error: Unable to open file Setting.txt \n";
	  }
	  else {
		  if (settingFile.is_open()) {
			  for (int i = 0; i < listInfo.size(settingCnt);i++) {
				  Display* dis;
				  if (display.get(i) == 0) {
					  dis = new Display();
				  }
				  else {
					  dis = display.get(i);
				  }
				  Sound* sou;
				  if (sound.get(i) == 0) {
					  sou = new Sound();
				  }
				  else {
					  sou = sound.get(i);
				  }
				  General* gen;
				  if (general.get(i) == 0) {
					  gen = new General();
				  }
				  else {
					  gen = general.get(i);
				  }
				  auto listinfo = listInfo.get(i);
				  settingFile << "Common: " << listinfo->getCarName() << ", " << listinfo->getEmail() << ", " << listinfo->getPersonalKey() << ", " << listinfo->getODO() << ", " << listinfo->getServiceRemind() << " "
					  << "Display: " << dis->get_light_level() << ", " << dis->get_screen_light_level() << ", " << dis->get_taplo_light_level() << " "
					  << "Sound: " << sou->get_media_level() << ", " << sou->get_call_level() << ", " << sou->get_navi_level() << ", " << sou->get_notification_level() << " "
					  << "General: " << gen->get_timeZone() << setw(0) << ", " << gen->get_language() << endl;
			  }
			  system("pause");
		  }
	  }
  }
  //hàm đọc dữ liệu từ file
  void MENU::readSetting() {
	  fstream in("Setting.txt");
	  if (in.is_open())
	  {
		  in.seekp(0, ios::end);
		  size_t size = in.tellg();
		  if (size == 0)
		  {
			  std::cout << "Setting.txt is empty\n";
			  system("pause");
			  return;
		  }
	  }
	  fstream settingFile("Setting.txt", ios_base::in);

	  if (!settingFile) {
		  std::cerr << "Error: file Setting.txt is not available \n";
	  }
	  else {
		  if (settingFile.is_open()) {
			  string input;
			  int count = -1;
			  while (getline(settingFile, input)) {
				  count++;
				  size_t start = input.find("Common: ");
				  if (start != string::npos) {
					  start += 8; // Move past "Common: "
					  size_t end = input.find(",", start); // Find the first comma after "Common: "
					  if (end != string::npos) {
						  string name = input.substr(start, end - start); // Extract "kien"
						  size_t start1 = start + name.length() + 2;
						  size_t end1 = input.find(",", start1);
						  string email = input.substr(start1, end1 - start1);
						  size_t start2 = start1 + email.length() + 2;
						  size_t end2 = input.find(",", start2);
						  string personkey = input.substr(start2, end2 - start2);
						  size_t start3 = start2 + personkey.length() + 2;
						  size_t end3 = input.find(",", start3);
						  string odo = input.substr(start3, end3 - start3);
						  size_t start4 = start3 + odo.length() + 2;
						  size_t end4 = input.find("D", start4);
						  string remind_service = input.substr(start4, end4 - start4);
						  size_t start5 = end4 + 9;
						  size_t end5 = input.find(",", start5);
						  string light_level = input.substr(start5, end5 - start5);
						  size_t start6 = end5 + 2;
						  size_t end6 = input.find(",", start6);
						  string screen_light_level = input.substr(start6, end6 - start6);
						  size_t start7 = end6 + 2;
						  size_t end7 = input.find("S", start7);
						  string taplo_light_level = input.substr(start7, end7 - start7);
						  size_t start8 = end7 + 7;
						  size_t end8 = input.find(",", start8);
						  string media = input.substr(start8, end8 - start8);
						  size_t start9 = end8 + 2;
						  size_t end9 = input.find(",", start9);
						  string call = input.substr(start9, end9 - start9);
						  size_t start10 = end9 + 2;
						  size_t end10 = input.find(",", start10);
						  string navi = input.substr(start10, end10 - start10);
						  size_t start11 = end10 + 2;
						  size_t end11 = input.find("G", start11);
						  string noti = input.substr(start11, end11 - start11);
						  size_t start12 = end11 + 9;
						  size_t end12 = input.find(",", start12);
						  string timezone = input.substr(start12, end12 - start12);
						  size_t start13 = end12 + 2;
						  size_t end13 = input.find(" ", start13);
						  string language = input.substr(start13, end13 - start13);
						  Setting* s1 = new Setting();
						  s1->setCarNamef(name);
						  s1->setKeynumberf(personkey);
						  s1->setEmailf(email);
						  int ododo = stoi(odo);
						  s1->setodof(ododo);
						  int remind = stoi(remind_service);
						  s1->setremindf(remind);
						  listInfo.add(s1, count);
						  settingCnt++;
						  Display* d1 = new Display();
						  int lightlevel = stoi(light_level);
						  d1->set_light_levelf(lightlevel);
						  int screenlight = stoi(screen_light_level);
						  d1->set_screen_light_levelf(screenlight);
						  int taplolight = stoi(taplo_light_level);
						  d1->set_taplo_light_levelf(taplolight);
						  display.add(d1, count);
						  dispCnt++;
						  Sound* so1 = new Sound();
						  int media_ = stoi(media);
						  so1->set_media_levelf(media_);
						  int call_ = stoi(call);
						  so1->set_call_levelf(call_);
						  int navi_ = stoi(navi);
						  so1->set_navi_levelf(navi_);
						  int noti_ = stoi(noti);
						  so1->set_notification_levelf(noti_);
						  sound.add(so1, count);
						  soundCnt++;
						  General* g1 = new General();
						  g1->set_languagef(language);
						  g1->set_timeZonef(timezone);
						  general.add(g1, count);
						  generalCnt++;

					  }
				  }
			  }
			  std::cout << "Successful Read and Input Data form Setting.txt !" << endl;
		  }
		  else {
			  std::cerr << "Error: Unable to open file Setting.txt \n";
		  }
	  }
	  system("pause");
  }
  //hàm add phần tử kiểu Setting* vào mảng setting
  void MENU::addSetting(Setting* setting) {
	  listInfo.add(setting, settingCnt);
	  settingCnt++;
	  std::cout << "-> This is new car, data will be appended to your list." << endl;
	  system("pause");
  }
  //generic template
  template<typename T1, typename T2, typename T3>
  void MENU::override(T1* info, T2* setting, List<T3>& listst, int i) {
	  listInfo.override(info, i);
	  listst.override(setting, i);
  }
  template<typename T1, typename T2, typename T3>
  void MENU::checkInfo(T1* inf, T2* set, List<T3>& list, int& cnt) {
	  int k = settingCnt;
	  bool m = true;
	  for (int i = 0; i < k;i++) {
		  auto listinfo = listInfo.get(i);
		  if (inf->getPersonalKey() == listinfo->getPersonalKey()) {
			  cout << "Match Personal Key at index: " << i << " of List!" << endl;
			  cout << "-> This is existed car, data will be overrided to your list." << endl;
			  system("pause");
			  set->nhapThongTin();
			  override(inf, set, list, i);
			  m = false;
			  break;
		  }
	  }
	  if (m) {
		  addSetting(inf);
		  set->nhapThongTin();
		  list.add(set, cnt);
		  cnt++;
	  }
  }
  // hiển thị màn hình 1
  void MENU::MH1() {
	  system("cls");
	  string choice;
	  regex ptnchoice("[1-3]{1}");
	  do {
		  std::cout << "--- SELECT MENU --- " << endl;
		  std::cout << "1. Input setting information" << endl;
		  std::cout << "2. Print setting information" << endl;
		  std::cout << "3. Exit" << endl;
		  std::cout << "Your selection: ";
		  std::getline(std::cin, choice);
		  if (regex_match(choice, ptnchoice) == false) {
			  system("cls");
			  std::cout << "UNVALID INPUT! Please set input integer 1-3!" << endl;
		  }
	  } while (regex_match(choice, ptnchoice) == false);
	  if (choice == "1") {
		  MH2();
	  }
	  if (choice == "2") {
		  MH3();
	  }
	  if (choice == "3") {
		  std::cout << "GOOD BYE!" << endl;
	  }
  }
  //hiển thị màn hình 2
  void MENU::MH2() {
	  system("cls");
	  string choice;
	  regex ptnchoice("[0-3]{1}");
	  do {
		  std::cout << "--- SELECT MENU --- " << endl;
		  std::cout << "1. Display setting" << endl;
		  std::cout << "2. Sound setting" << endl;
		  std::cout << "3. General Setting" << endl;
		  std::cout << "0. Exit" << endl;
		  std::cout << "Your selection: ";
		  std::getline(std::cin, choice);
		  if (regex_match(choice, ptnchoice) == false) {
			  system("cls");
			  std::cout << "UNVALID INPUT! Please set input integer 0-3" << endl;
		  }
	  } while (regex_match(choice, ptnchoice) == false);
	  if (choice == "1") {
		  system("cls");
		  NhapThongTinCaiDat_Display();
		  MH2();
	  }
	  if (choice == "2") {
		  system("cls");
		  NhapThongTinCaiDat_Sound();
		  MH2();
	  }
	  if (choice == "3") {
		  system("cls");
		  NhapThongTinCaiDat_General();
		  MH2();
	  }
	  if (choice == "0") {
		  MH1();
	  }
  }
  //hiển thị màn hình 3
  void MENU::MH3() {
	  system("cls");
	  string choice;
	  regex ptnchoice("[0-4]{1}");
	  do {
		  std::cout << "--- SELECT MENU --- " << endl;
		  std::cout << "1. Print Display setting information" << endl;
		  std::cout << "2. Print Sound setting information" << endl;
		  std::cout << "3. Print General setting information" << endl;
		  std::cout << "4. Print all setting information" << endl;
		  std::cout << "0. Exit" << endl;
		  std::cout << "Your selection: ";
		  std::getline(std::cin, choice);
		  if (regex_match(choice, ptnchoice) == false) {
			  system("cls");
			  std::cout << "UNVALID INPUT! Please set input integer 0-4" << endl;
		  }
	  } while (regex_match(choice, ptnchoice) == false);
	  if (choice == "1") {
		  system("cls");
		  std::cout << "--- Display setting ---" << endl;
		  XuatThongTinCaiDat_Display();
		  system("pause");
		  MH1();

	  }
	  if (choice == "2") {
		  std::cout << "--- Sound setting ---" << endl;
		  XuatThongTinCaiDat_Sound();
		  system("pause");
		  MH1();
	  }
	  if (choice == "3") {
		  std::cout << "--- General setting ---" << endl;
		  XuatThongTinCaiDat_General();
		  system("pause");
		  MH1();
	  }
	  if (choice == "4") {
		  XuatThongTatCaTinCaiDat();
	  }
	  if (choice == "0") {
		  MH1();
	  }
  }
  //nhập thông tin cài đặt cho kiểu dữ liệu display
  void MENU::NhapThongTinCaiDat_Display()
  {
	  char continues = 'n';

	  do {
		  Display* d1 = new Display();
		  Setting* sd = new Setting();
		  if (dispCnt < MAX()) {
			  std::cout << "Car index: " << dispCnt << endl;
			  d1->nhapThongTin();
			  display.add(d1, dispCnt);
			  dispCnt++;
			  filesetting();
			  std::cout << "TIEP TUC XE SO " << dispCnt + 1 << " ? (y/n): ";
			  std::cin >> continues;
			  if (continues == 'n') {
				  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
				  break;
			  }
			  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  }
		  else {
			  system("cls");
			  std::cout << "Car index: " << settingCnt << endl;
			  sd->nhapThongTin();
			  if (settingCnt == 0) {
				  addSetting(sd);
				  d1->nhapThongTin();
				  display.add(d1, dispCnt);
				  dispCnt++;
			  }
			  else {
				  checkInfo(sd, d1, display, dispCnt);
			  }
			  filesetting();
			  std::cout << "TIEP TUC XE SO " << settingCnt + 1 << " ? (y/n): ";
			  std::cin >> continues;
			  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  }
	  } while (continues == 'y');
  }
  //nhập thông tin cho kiểu dữ liệu sound
  void MENU::NhapThongTinCaiDat_Sound()
  {
	  char continues = 'n';
	  do {
		  Sound* sou1 = new Sound();
		  Setting* sdou = new Setting();
		  if (soundCnt < MAX()) {
			  std::cout << "Car index: " << soundCnt << endl;
			  sou1->nhapThongTin();
			  sound.add(sou1, soundCnt);
			  soundCnt++;
			  filesetting();
			  std::cout << "TIEP TUC XE SO " << soundCnt + 1 << " ? (y/n): ";
			  std::cin >> continues;
			  if (continues == 'n') {
				  break;
				  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
			  }
			  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  }
		  else {
			  system("cls");
			  std::cout << "Car index: " << settingCnt << endl;
			  sdou->nhapThongTin();
			  if (settingCnt == 0) {
				  addSetting(sdou);
				  sou1->nhapThongTin();
				  sound.add(sou1, soundCnt);
				  soundCnt++;
			  }
			  else {
				  checkInfo(sdou, sou1, sound, soundCnt);
			  }
			  filesetting();
			  std::cout << "TIEP TUC XE SO " << settingCnt + 1 << " ? (y/n): ";
			  std::cin >> continues;
			  std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
		  }
	  } while (continues == 'y');

  }
  //nhập thông tin cho kiểu dữ liệu general
  void MENU:: NhapThongTinCaiDat_General()
  {
	  fstream timeZoneFile("timezones.txt", ios_base::in);
	  fstream languageFile("languages.txt", ios_base::in);
	  char continues = 'n';
	  if (timeZoneFile.is_open() && (languageFile.is_open())) {
		  do {
			  General* g1 = new General();
			  Setting* sgen = new Setting();
			  if (generalCnt < MAX()) {
				  system("cls");
				  std::cout << "Car index: " << generalCnt << endl;
				  system("pause");
				  g1->nhapThongTin();
				  general.add(g1, generalCnt);
				  generalCnt++;
				  filesetting();
				  std::cout << "TIEP TUC XE SO " << generalCnt + 1 << " ? (y/n): ";
				  cin >> continues;
				  if (continues == 'n') {
					  cin.ignore(numeric_limits<streamsize>::max(), '\n');
					  break;
				  }
				  cin.ignore(numeric_limits<streamsize>::max(), '\n');
			  }
			  else {
				  system("cls");
				  std::cout << "Car index: " << settingCnt << endl;
				  system("pause");
				  sgen->nhapThongTin();
				  if (settingCnt == 0) {
					  addSetting(sgen);
					  cin.ignore();
					  g1->nhapThongTin();
					  general.add(g1, generalCnt);
					  generalCnt++;
				  }
				  else {
					  cin.ignore();
					  checkInfo(sgen, g1, general, generalCnt);
				  }
				  filesetting();
				  std::cout << "TIEP TUC XE SO " << settingCnt + 1 << " ? (y/n): ";
				  cin >> continues;
				  cin.ignore(numeric_limits<streamsize>::max(), '\n');
			  }
		  } while (continues == 'y');
	  }
	  else {
		  std::cerr << "Error: Unable to open file language.txt and file timezones.txt \n";
		  system("pause");
	  }
  }
  //Các hàm xuất thông tin cài đặt: xuất tất cả, xuất general, xuất display, xuất sound
  void MENU::XuatThongTinCaiDat_Display() {
	  if (display.size(dispCnt) == 0) {
		  std::cout << " ==> CHUA NHAP THONG TIN DISPLAY CHO XE NAO! " << endl;
		  system("pause");
		  MH3();
	  }
	  else {
		  for (int i = 0; i < display.size(dispCnt); i++) {
			  auto disp = display.get(i);
			  auto setdisp = listInfo.get(i);
			  if (disp && setdisp) {
				  std::cout << left << setw(5) << i + 1 << "\t" << setw(20) << "Owner Name" << setw(25) << "Email" << setw(20) << "Key number" << setw(20) << "ODO number" << setw(20) << "Remind service (km)" << endl
					  << "\t" << setw(20) << setdisp->getCarName() << setw(25) << setdisp->getEmail() << setw(20) << setdisp->getPersonalKey() << setw(20) << setdisp->getODO() << setw(20) << setdisp->getServiceRemind() << endl
					  << "\t" << setw(15) << "Display:" << setw(10) << "Light" << setw(15) << "Screen Light" << setw(15) << "Taplo Light" << endl
					  << setw(16) << "\t" << setw(10) << disp->get_light_level() << setw(15) << disp->get_screen_light_level() << setw(15) << disp->get_taplo_light_level() << endl;
			  }
			  else {
				  std::cout << "Invalid display object at index " << i << endl;
			  }
		  }
	  }
	  system("pause");
	  MH3();
  }
  void MENU::XuatThongTinCaiDat_General() {
	  system("cls");
	  if (general.size(generalCnt) == 0) {
		  std::cout << " ==> CHUA NHAP THONG TIN GENERAL CHO XE NAO! " << endl;
		  system("pause");
		  MH3();
	  }
	  else {
		  for (int i = 0; i < general.size(generalCnt); i++) {
			  auto gene = general.get(i);
			  auto setgene = listInfo.get(i);
			  if (gene && setgene) {
				  std::cout << left << setw(5) << i + 1 << "\t" << setw(20) << "Owner Name" << setw(25) << "Email" << setw(20) << "Key number" << setw(20) << "ODO number" << setw(20) << "Remind service (km)" << endl
					  << "\t" << setw(20) << setgene->getCarName() << setw(25) << setgene->getEmail() << setw(20) << setgene->getPersonalKey() << setw(20) << setgene->getODO() << setw(20) << setgene->getServiceRemind() << endl
					  << "\t" << setw(15) << "General:" << setw(25) << "Time zone" << setw(15) << "Language" << endl
					  << setw(16) << "\t" << setw(25) << gene->get_timeZone() << setw(15) << gene->get_language() << endl;
			  }
			  else {
				  std::cout << "Invalid display object at index " << i << endl;
			  }
		  }
	  }
	  system("pause");
	  MH3();
  }
  void MENU::XuatThongTinCaiDat_Sound() {
	  system("cls");
	  if (sound.size(soundCnt) == 0) {
		  std::cout << " ==> CHUA NHAP THONG TIN SOUND CHO XE NAO! " << endl;
		  system("pause");
		  MH3();
	  }
	  else {
		  for (int i = 0; i < sound.size(soundCnt); i++) {
			  auto sou = sound.get(i);
			  auto setsou = listInfo.get(i);
			  if (sou) {
				  std::cout << left << setw(5) << i + 1 << "\t" << setw(20) << "Owner Name" << setw(25) << "Email" << setw(20) << "Key number" << setw(20) << "ODO number" << setw(20) << "Remind service (km)" << endl
					  << "\t" << setw(20) << setsou->getCarName() << setw(25) << setsou->getEmail() << setw(20) << setsou->getPersonalKey() << setw(20) << setsou->getODO() << setw(20) << setsou->getServiceRemind() << endl
					  << "\t" << setw(15) << "Sound:" << setw(10) << "Media" << setw(15) << "Call" << setw(15) << "Navigation" << setw(15) << "Notification" << endl
					  << setw(16) << "\t" << setw(10) << sou->get_media_level() << setw(15) << sou->get_call_level() << setw(15) << sou->get_navi_level() << setw(15) << sou->get_notification_level() << endl;
			  }
			  else {
				  std::cout << "Invalid display object at index " << i << endl;
			  }
		  }
	  }
	  system("pause");
	  MH3();
  }
  void MENU:: XuatThongTatCaTinCaiDat() {
	  system("cls");
	  if (listInfo.size(settingCnt) == 0) {
		  std::cout << " ==> CHUA NHAP THONG TIN CHO XE NAO! " << endl;
		  system("pause");
		  MH3();
	  }
	  else {
		  std::cout << "--- All Setting ---" << endl;
		  for (int i = 0; i < listInfo.size(settingCnt);i++) {
			  Display* dis;
			  if (display.get(i) == 0) {
				  dis = new Display();
			  }
			  else {
				  dis = display.get(i);
			  }
			  Sound* sou;
			  if (sound.get(i) == 0) {
				  sou = new Sound();
			  }
			  else {
				  sou = sound.get(i);
			  }
			  General* gen;
			  if (general.get(i) == 0) {
				  gen = new General();
			  }
			  else {
				  gen = general.get(i);
			  }
			  auto listinfo = listInfo.get(i);
			  std::cout << left << setw(5) << i + 1 << "\t" << setw(20) << "Owner Name" << setw(25) << "Email" << setw(20) << "Key number" << setw(20) << "ODO number" << setw(20) << "Remind service (km)" << endl
				  << "\t" << setw(20) << listinfo->getCarName() << setw(25) << listinfo->getEmail() << setw(20) << listinfo->getPersonalKey() << setw(20) << listinfo->getODO() << setw(20) << listinfo->getServiceRemind() << endl
				  << "\t" << setw(15) << "Display:" << setw(10) << "Light" << setw(15) << "Screen Light" << setw(15) << "Taplo Light" << endl
				  << setw(16) << "\t" << setw(10) << dis->get_light_level() << setw(15) << dis->get_screen_light_level() << setw(15) << dis->get_taplo_light_level() << endl
				  << "\t" << setw(15) << "Sound:" << setw(10) << "Media" << setw(15) << "Call" << setw(15) << "Navigation" << setw(15) << "Notification" << endl
				  << setw(16) << "\t" << setw(10) << sou->get_media_level() << setw(15) << sou->get_call_level() << setw(15) << sou->get_navi_level() << setw(15) << sou->get_notification_level() << endl
				  << "\t" << setw(15) << "General:" << setw(25) << "Time zone" << setw(15) << "Language" << endl
				  << setw(16) << "\t" << setw(25) << gen->get_timeZone() << setw(15) << gen->get_language() << endl;
		  }
	  }
	  system("pause");
	  MH3();
  }
