#pragma region includes 
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <time.h>
#include "myerror.h"
#include <SFML/System/Clock.hpp>
////////Гости и персонал///////////
#include "peopleGenerator.h"
#include "Person.h"
#include "Guest.h"
#include "Cashier.h"
#include "Assistant.h"
#include "ClassList.h"
#include "ShopQueue.h"
///////////////////////////////////
 #include <Windows.h> // Для того, чтобы посмотреть путь к файлам

#pragma endregion

// Функция получает на вход имя шрифта
// Выдаёт шрифт, который используется при написании текста
sf::Font setFont(std::string fname) {
	sf::Font font;
	try {
		bool isOk = font.loadFromFile(fname);
		if (!isOk)
			throw(fname);
	}
	catch(...){
		std::cerr << "Файл, содержащий шрифт " << fname << ", не найден";
	}
	return font;
}

// Получение текста 
// нужен вывод на экран для отображения
//	window.draw(*textexample);
sf::Text * writeText(std::string textToWrite, sf::Font font, sf::Color clr, int size) {
	sf::Text * text = new sf::Text(textToWrite, font, size);
	text->setFillColor(clr);
	return text;
}

int main()
{

// Версия 1.0.1 
// 

	setlocale(LC_ALL, "Russian");
	sf::RenderWindow window(sf::VideoMode(800, 600), L"Моделирование супермаркета");
	window.setFramerateLimit(60);

	int screenSwitch = 0;	// Переключение с окна настройки на окно моделлирования

//###########################################################################//
//***************************************************************************//
//					Создание общих оконных элементов 						 //
//***************************************************************************//
//###########################################################################//
#pragma region CommonElements

	//char path[MAX_PATH];
	//GetCurrentDirectoryA(MAX_PATH, path);
	//MessageBoxA(NULL, path, "Current Directory", MB_OK);

	std::string fontName = "Roboto-Regular.ttf";			// !!! Не забыть об имени папки если имеется и расширении!!!
	sf::Font font = setFont(fontName);						// Шрифт в папке с .cpp и .h файлами

															// Создание заднего фона
	sf::Vector2f * backgroundsize = new sf::Vector2f(800.f, 600.f);
	sf::RectangleShape * background = new sf::RectangleShape(*backgroundsize);

	background->setFillColor(sf::Color(225, 225, 225, 255));
	
#pragma endregion
//###########################################################################//
//***************************************************************************//
//					Создание элементов экрана настроек						 //
//***************************************************************************//
//###########################################################################//
#pragma region OptionsElements
	sf::Color * darkGreen = new sf::Color(50, 155, 50, 255);
	sf::Color * darkRed = new sf::Color(155, 50, 50, 255);	

	// Задний фон DEBUG пиксельная разметка
	//auto BGOptionsDebugI = new sf::Image();
	//std::string BGOptionsDebugFilename = "BGoptions.png"; // Не забыть расширение!
	//try
	//{
	//	if (!BGOptionsDebugI->loadFromFile("Images/" + BGOptionsDebugFilename))
	//		throw Filerr(BGOptionsDebugFilename);	
	//}
	//catch (Filerr& noFile)
	//{
	//	noFile.print();
	//}
	//auto BGOptionsDebugT = new sf::Texture();
	//BGOptionsDebugT->loadFromImage(*BGOptionsDebugI);
	//auto BGOptionsDebug = new sf::Sprite(*BGOptionsDebugT);

	//////////////////////////////////////////////////////////////////////////////	
	sf::RectangleShape * buttonStartModel =
		new sf::RectangleShape(sf::Vector2f(200.f, 75.f));
	buttonStartModel->setPosition(sf::Vector2f(300.f, 515.f));
	buttonStartModel->setFillColor(*darkGreen);	

	sf::Text * textStartModelling = new sf::Text(L"Начать", font, 25);
	textStartModelling->setPosition(358.0, 535.0);
	textStartModelling->setFillColor(sf::Color::Black);

	// ######  Настройка количества касс ###### //
	sf::RectangleShape * buttonPlusSeller =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonPlusSeller->setPosition(sf::Vector2f(235.f, 20.f));
	buttonPlusSeller->setFillColor(*darkGreen);

	sf::Text * textPlusSeller = new sf::Text("+", font, 30);
	textPlusSeller->setPosition(250.0, 20.0);
	textPlusSeller->setFillColor(sf::Color::Black);

	sf::Text * textMinusSeller = new sf::Text("-", font, 40);
	textMinusSeller->setPosition(253.0, 55.0);
	textMinusSeller->setFillColor(sf::Color::Black);

	sf::RectangleShape * buttonMinusSeller =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonMinusSeller->setPosition(sf::Vector2f(235.f, 60.f));
	buttonMinusSeller->setFillColor(*darkRed);

	sf::Text * textNumberOfSellers = new sf::Text(L"Количество касс:", font, 25);
	textNumberOfSellers->setPosition(25.0, 50.0);
	textNumberOfSellers->setFillColor(sf::Color::Black);

	// ######  Настройка количества ассистентов ###### //
	sf::RectangleShape * buttonPlusAssistant =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonPlusAssistant->setPosition(sf::Vector2f(615.f, 20.f));
	buttonPlusAssistant->setFillColor(*darkGreen);

	sf::Text * textPlusAssistant = new sf::Text("+", font, 30);
	textPlusAssistant->setPosition(630.0, 20.0);
	textPlusAssistant->setFillColor(sf::Color::Black);

	sf::Text * textMinusAssistant = new sf::Text("-", font, 40);
	textMinusAssistant->setPosition(633.0, 55.0);
	textMinusAssistant->setFillColor(sf::Color::Black);

	sf::RectangleShape * buttonMinusAssistant =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonMinusAssistant->setPosition(sf::Vector2f(615.f, 60.f));
	buttonMinusAssistant->setFillColor(*darkRed);

	sf::Text * textNumberOfAssistants = new sf::Text(L"Количество", font, 25);
	textNumberOfAssistants->setPosition(425.0, 35.0);
	textNumberOfAssistants->setFillColor(sf::Color::Black);

	sf::Text * textNumberOfAssistants2 = new sf::Text(L"консультантов:", font, 25);
	textNumberOfAssistants2->setPosition(425.0, 65.0);
	textNumberOfAssistants2->setFillColor(sf::Color::Black);

	// ######  Настройка периода моделирования ###### //
	sf::RectangleShape * buttonPlusModellingTime =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonPlusModellingTime->setPosition(sf::Vector2f(235.f, 120.f));
	buttonPlusModellingTime->setFillColor(*darkGreen);

	sf::Text * textPlusModellingTime = new sf::Text("+", font, 30);
	textPlusModellingTime->setPosition(250.0, 120.0);
	textPlusModellingTime->setFillColor(sf::Color::Black);

	sf::Text * textMinusModellingTime = new sf::Text("-", font, 40);
	textMinusModellingTime->setPosition(253.0, 155.0);
	textMinusModellingTime->setFillColor(sf::Color::Black);

	sf::RectangleShape * buttonMinusModellingTime =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonMinusModellingTime->setPosition(sf::Vector2f(235.f, 160.f));
	buttonMinusModellingTime->setFillColor(*darkRed);

	sf::Text * textModellingTime1 = new sf::Text(L"Период", font, 25);
	textModellingTime1->setPosition(25.0, 130.0);
	textModellingTime1->setFillColor(sf::Color::Black);

	sf::Text * textModellingTime2 = new sf::Text(L"моделирования:", font, 25);
	textModellingTime2->setPosition(25.0, 160.0);
	textModellingTime2->setFillColor(sf::Color::Black);

	// ######  Настройка стоимости покупки ###### //
	// Кнопка + от
	sf::RectangleShape * buttonPlusPriceCost =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonPlusPriceCost->setPosition(sf::Vector2f(235.f, 220.f));
	buttonPlusPriceCost->setFillColor(*darkGreen);

	sf::Text * textPlusPriceCost = new sf::Text("+", font, 30);
	textPlusPriceCost->setPosition(250.0, 220.0);
	textPlusPriceCost->setFillColor(sf::Color::Black);

	// Кнопка + до
	sf::RectangleShape * buttonPlusPriceCost2 =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonPlusPriceCost2->setPosition(sf::Vector2f(385.f, 220.f));
	buttonPlusPriceCost2->setFillColor(*darkGreen);

	sf::Text * textPlusPriceCost2 = new sf::Text("+", font, 30);
	textPlusPriceCost2->setPosition(400.0, 220.0);
	textPlusPriceCost2->setFillColor(sf::Color::Black);

	// Кнопка - от
	sf::RectangleShape * buttonMinusPriceCost =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonMinusPriceCost->setPosition(sf::Vector2f(235.f, 260.f));
	buttonMinusPriceCost->setFillColor(*darkRed);

	sf::Text * textMinusPriceCost = new sf::Text("-", font, 40);
	textMinusPriceCost->setPosition(253.0, 255.0);
	textMinusPriceCost->setFillColor(sf::Color::Black);

	// Кнопка - до
	sf::RectangleShape * buttonMinusPriceCost2 =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonMinusPriceCost2->setPosition(sf::Vector2f(385.f, 260.f));
	buttonMinusPriceCost2->setFillColor(*darkRed);

	sf::Text * textMinusPriceCost2 = new sf::Text("-", font, 40);
	textMinusPriceCost2->setPosition(403.0, 255.0);
	textMinusPriceCost2->setFillColor(sf::Color::Black);

	// Текст - информация

	sf::Text * textPriceCost11 = new sf::Text(L"Стоимость", font, 25);
	textPriceCost11->setPosition(25.0, 230.0);
	textPriceCost11->setFillColor(sf::Color::Black);

	sf::Text * textPriceCost12 = new sf::Text(L"покупки от и до:", font, 25);
	textPriceCost12->setPosition(25.0, 260.0);
	textPriceCost12->setFillColor(sf::Color::Black);

	// ######  Настройка размера скидки ###### //
	sf::RectangleShape * buttonPlusSalePercent =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonPlusSalePercent->setPosition(sf::Vector2f(235.f, 320.f));
	buttonPlusSalePercent->setFillColor(*darkGreen);

	sf::Text * textPlusSalePercent = new sf::Text("+", font, 30);
	textPlusSalePercent->setPosition(250.0, 320.0);
	textPlusSalePercent->setFillColor(sf::Color::Black);

	sf::Text * textMinusSalePercent = new sf::Text("-", font, 40);
	textMinusSalePercent->setPosition(253.0, 355.0);
	textMinusSalePercent->setFillColor(sf::Color::Black);

	sf::RectangleShape * buttonMinusSalePercent =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonMinusSalePercent->setPosition(sf::Vector2f(235.f, 360.f));
	buttonMinusSalePercent->setFillColor(*darkRed);

	sf::Text * textSalePercent1 = new sf::Text(L"Процент", font, 25);
	textSalePercent1->setPosition(25.0, 330.0);
	textSalePercent1->setFillColor(sf::Color::Black);

	sf::Text * textSalePercent2 = new sf::Text(L"скидки:", font, 25);
	textSalePercent2->setPosition(25.0, 360.0);
	textSalePercent2->setFillColor(sf::Color::Black);

	// Реклама - да или нет?

	sf::RectangleShape * buttonIfAds =
		new sf::RectangleShape(sf::Vector2f(50.f, 40.f));
	buttonIfAds->setPosition(sf::Vector2f(235.f, 435.f));
	buttonIfAds->setFillColor(*darkRed);

	sf::Text * textIsAds = new sf::Text("X", font, 30);
	textIsAds->setPosition(250.0, 435.0);
	textIsAds->setFillColor(sf::Color::Black);

	sf::Text * textAds = new sf::Text(L"Есть реклама?", font, 25);
	textAds->setPosition(25.0, 445.0);
	textAds->setFillColor(sf::Color::Black);
#pragma endregion
//###########################################################################//
//***************************************************************************//
//					Создание элементов экрана моделирования					 //
//***************************************************************************//
//###########################################################################//
#pragma region ModelElements
//***************************************************************************//
//		Блок для создания статических графических элементов интерфейса       //
//***************************************************************************//
	sf::Color * darkness = new sf::Color(0, 0, 0, 30);
	auto night = new sf::RectangleShape(sf::Vector2f(600.f, 400.f));
	night->setPosition(0.f, 100.f);
	night->setFillColor(*darkness);

	// Дизайн магазина
	auto BGShopI = new sf::Image();
	std::string BGShopFilename = "BGShop.jpg"; // Не забыть расширение!
	try
	{
		if (!BGShopI->loadFromFile("Images/" + BGShopFilename))
			throw Filerr(BGShopFilename);
	}
	catch (Filerr& noFile)
	{
		noFile.print();
	}
	auto BGShopT = new sf::Texture();
	BGShopT->loadFromImage(*BGShopI);
	auto BGShop = new sf::Sprite(*BGShopT);
	BGShop->setPosition(0.f, 100.f);

	// Графика: покупатель №1
	auto SpriteGuest1I = new sf::Image();
	SpriteGuest1I->createMaskFromColor(sf::Color(60, 255, 13));
	std::string SpriteGuest1Filename = "SpriteGuest1.jpg"; // Не забыть расширение!
	try
	{
		if (!SpriteGuest1I->loadFromFile("Images/" + SpriteGuest1Filename))
			throw Filerr(SpriteGuest1Filename);
	}
	catch (Filerr& noFile)
	{
		noFile.print();
	}
	auto SpriteGuest1T = new sf::Texture();
	SpriteGuest1T->loadFromImage(*SpriteGuest1I);

	// Графика: покупатель №2
	auto SpriteGuest2I = new sf::Image();
	std::string SpriteGuest2Filename = "SpriteGuest2.jpg"; // Не забыть расширение!
	try
	{
		if (!SpriteGuest2I->loadFromFile("Images/" + SpriteGuest2Filename))
			throw Filerr(SpriteGuest2Filename);
	}
	catch (Filerr& noFile)
	{
		noFile.print();
	}
	auto SpriteGuest2T = new sf::Texture();
	SpriteGuest2T->loadFromImage(*SpriteGuest2I);

	// Графика: покупатель №3
	auto SpriteGuest3I = new sf::Image();
	std::string SpriteGuest3Filename = "SpriteGuest3.jpg"; // Не забыть расширение!
	try
	{
		if (!SpriteGuest3I->loadFromFile("Images/" + SpriteGuest3Filename))
			throw Filerr(SpriteGuest3Filename);
	}
	catch (Filerr& noFile)
	{
		noFile.print();
	}
	auto SpriteGuest3T = new sf::Texture();
	SpriteGuest3T->loadFromImage(*SpriteGuest3I);

	// Графика: покупатель №4
	auto SpriteGuest4I = new sf::Image();
	std::string SpriteGuest4Filename = "SpriteGuest4.jpg"; // Не забыть расширение!
	try
	{
		if (!SpriteGuest4I->loadFromFile("Images/" + SpriteGuest4Filename))
			throw Filerr(SpriteGuest4Filename);
	}
	catch (Filerr& noFile)
	{
		noFile.print();
	}
	auto SpriteGuest4T = new sf::Texture();
	SpriteGuest4T->loadFromImage(*SpriteGuest4I);

	// Графика: кассир и консультант
	auto SpriteSellerI = new sf::Image();
	std::string SpriteSellerFilename = "SpriteAssistant.jpg"; // Не забыть расширение!
	try
	{
		if (!SpriteSellerI->loadFromFile("Images/" + SpriteSellerFilename))
			throw Filerr(SpriteSellerFilename);
	}
	catch (Filerr& noFile)
	{
		noFile.print();
	}
	auto SpriteSellerT = new sf::Texture();
	SpriteSellerT->loadFromImage(*SpriteSellerI);

	std::vector <sf::Sprite *> GuestSprites;
	std::vector <sf::Sprite *> GuestAssistantSprites;
	std::vector <sf::Sprite *> GuestSellerSprites;

	auto SpriteSeller = new sf::Sprite(*SpriteSellerT);


	sf::RectangleShape * verticalLineStatistics =
		new sf::RectangleShape(sf::Vector2f(15.f, 500.f));
	verticalLineStatistics->setPosition(sf::Vector2f(600.f, 0.f));
	verticalLineStatistics->setFillColor(sf::Color::Black);

	sf::RectangleShape * horizontalLineStatistics =
		new sf::RectangleShape(sf::Vector2f(600.f, 15.f));
	horizontalLineStatistics->setPosition(sf::Vector2f(0.f, 95.f));
	horizontalLineStatistics->setFillColor(sf::Color::Black);

	sf::RectangleShape * horizontalLineMaxQ =
		new sf::RectangleShape(sf::Vector2f(200.f, 15.f));
	horizontalLineMaxQ->setPosition(sf::Vector2f(600.f, 190.f));
	horizontalLineMaxQ->setFillColor(sf::Color::Black);

	sf::RectangleShape * horizontalLineBottomStatistics =
		new sf::RectangleShape(sf::Vector2f(800.f, 15.f));
	horizontalLineBottomStatistics->setPosition(sf::Vector2f(0.f, 490.f));
	horizontalLineBottomStatistics->setFillColor(sf::Color::Black);

	//***************************************************************************//
	//		Блок для создания статических текстовых	элементов интерфейса         //
	//***************************************************************************//
	sf::Text * textTimePassedInfo = new sf::Text(L"Прошло реального времени:", font, 25);
	textTimePassedInfo->setPosition(15.0, 15.0);
	textTimePassedInfo->setFillColor(sf::Color::Black);

	sf::Text * textModelTimePassedInfo = new sf::Text(L"Прошло минут в модели:", font, 25);
	textModelTimePassedInfo->setPosition(15.0, 45.0);
	textModelTimePassedInfo->setFillColor(sf::Color::Black);

	sf::Text * textMoneyGotString1 = new sf::Text(L"Полученная", font, 25);
	textMoneyGotString1->setPosition(625.0, 15.0);
	textMoneyGotString1->setFillColor(sf::Color::Black);

	sf::Text * textMoneyGotString2 = new sf::Text(L"прибыль", font, 25);
	textMoneyGotString2->setPosition(625.0, 35.0);
	textMoneyGotString2->setFillColor(sf::Color::Black);

	sf::Text * textGuestsGotString1 = new sf::Text(L"Посетителей", font, 25);
	textGuestsGotString1->setPosition(625.0, 105.0);
	textGuestsGotString1->setFillColor(sf::Color::Black);

	sf::Text * textGuestsGotString2 = new sf::Text(L"за все время", font, 25);
	textGuestsGotString2->setPosition(625.0, 125.0);
	textGuestsGotString2->setFillColor(sf::Color::Black);

	sf::Text * textMaxQString1 = new sf::Text(L"Максимальная", font, 25);
	textMaxQString1->setPosition(622.5, 225.0);
	textMaxQString1->setFillColor(sf::Color::Black);

	sf::Text * textMaxQString2 = new sf::Text(L"очередь", font, 25);
	textMaxQString2->setPosition(622.5, 245.0);
	textMaxQString2->setFillColor(sf::Color::Black);

	sf::Text * textMaxQString3 = new sf::Text(L"у кассы:", font, 25);
	textMaxQString3->setPosition(622.5, 265.0);
	textMaxQString3->setFillColor(sf::Color::Black);

	sf::Text * textMaxQString4 = new sf::Text(L"у продавцов -", font, 25);
	textMaxQString4->setPosition(622.5, 320.0);
	textMaxQString4->setFillColor(sf::Color::Black);

	sf::Text * textMaxQString5 = new sf::Text(L"консультантов:", font, 25);
	textMaxQString5->setPosition(622.5, 345.0);
	textMaxQString5->setFillColor(sf::Color::Black);

	// Количество продавцов и ассистентов в активной модели
	sf::Text * textSellersActive = new sf::Text(L"Активных касс: ", font, 25);
	textSellersActive->setPosition(25.5, 520.0);
	textSellersActive->setFillColor(sf::Color::Black);

	sf::Text * textAssistantsActive = new sf::Text(L"Консультантов:", font, 25);
	textAssistantsActive->setPosition(25.5, 550.0);
	textAssistantsActive->setFillColor(sf::Color::Black);

	sf::Text * textGuestsLeft = new sf::Text(L"Покупателей ", font, 25);
	textGuestsLeft->setPosition(275.5, 520.0);
	textGuestsLeft->setFillColor(sf::Color::Black);

	sf::Text * textGuestsLeft2 = new sf::Text(L"потеряно:", font, 25);
	textGuestsLeft2->setPosition(295.5, 550.0);
	textGuestsLeft2->setFillColor(sf::Color::Black);

#pragma endregion
	//***************************************************************************//
	//		Конец описания статических графических элементов интерфейса			 //
	//***************************************************************************//
#pragma region shop logic
	sf::Clock modelTime;

	int modellingTime = 60;					// ИЗМЕНЯЕМО - период моделировани
	// При большом времени моделлирования кассы заполняются неравномерно. Исправим это.
	// Примерно равно количеству обслуживаемых покупателей в период моделлирования
	int modellingTimeFixQueues = modellingTime / 5; 

	// Создадим кассы и консультантов. Каждый из них содержит изначально пустую очередь клиентов.

	int SellersCount = 3;					// ИЗМЕНЯЕМО
	int AssistantsCount = 3;				// ИЗМЕНЯЕМО

	MyList * Terminals = new MyList();		// Список всех касс
	MyList * Assistants = new MyList();		// Список всех консультантов



	//***************************************************************************//
	//			Следующий блок кода ответственный за создание рандома			 //
	//			появления людей в магазине. Вспомогательный файл с функциями:	 //
	//			peopleGenerator.h												 //
	//***************************************************************************//

	// Для возможности применения модификаторов увеличения посетителей,
	// Принимаем минуту за 100 условных единиц

	unsigned int rand_value = 0;
	std::srand(rand_value);
	
	//***************************************************************************//
	//			Расчёт вероятности прихода покупателей в магазин				 //
	//***************************************************************************//
	float modifiedChanceOfAppearanceD = 500.0; // !! Чем меньше, тем выше

	bool isAdsOn = false; 

	// Каждые 2% скидки увеличивает кол-во покупателей на 1%
	double lowerPricePercent = 0;
	
	// Преобразованный в int modifiedChanceOfAppearanceD
	// Чем выше, тем ХУЖЕ
	int modifiedChanceOfAppearanceInt;
	
	// Сколько людей зашло в магазин
	std::pair <int, int> peopleCreatedRandom;
	int peopleCreated = peopleCreatedRandom.first;
	// timeleft - лишнее время. 
	// Например, если на 59-ой секунде зашёл покупатель, и следующий,
	// допустим на 65-ой, то мы вычитаем 5 из следующего времени, после
	// которого запускаются новые покупатели, результат в nextGuestsComingTime
	int timeleft = peopleCreatedRandom.second;
	int nextGuestsComingTime = modellingTime - timeleft;

	int numberOfGuests = 0;
	int numberofGuestsLeft = 0;
	sf::Time start = modelTime.getElapsedTime();

	// Следующие числовые переменные являются вспомогательными для
	// запуска соответствующих им блоков (период, день, день/ночь)
	int expectedGuestProceedPeriod = 0;		// Номер периода обновления посетителей
	int expectedDayUpdate = 0;				// Номер текущего дня. 

	ShopQueue * Guests = new ShopQueue();	// Очередь, содержащая всех покупателей

	int maxQSeller = 7;
	int maxQAssistant = 3;

	//***************************************************************************//
	//		Блок для инициализации переменных работы с деньгами			         //
	//***************************************************************************//
	double moneyResult = 0;
	float moneyMultiplier = 0.09f;
	moneyMultiplier *= (100 - lowerPricePercent) * 0.01f;
	int moneyPaid = 1500;
	int moneyForAds = 0;

	int priceCostMin = 30;
	int priceCostMax = 9000;
#pragma endregion


	while (window.isOpen())
	{
		switch (screenSwitch)		// Модель или настройки?
		{
		case 0: 
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::MouseButtonPressed) {
					if (event.mouseButton.x >= 300 && event.mouseButton.x <= 500
						&& event.mouseButton.y >= 515 && event.mouseButton.y <= 585
						&& event.mouseButton.button == sf::Mouse::Button::Left) {
						screenSwitch = 1;
						// Создание N касс, где N указано на экране 
						// настройки моделирования
						for (int i = 0; i < SellersCount; i++) {
							Cashier * newTerminal = new Cashier();
							Terminals->push(newTerminal);
						}

						for (int i = 0; i < AssistantsCount; i++) {
							Assistant * newAssistant = new Assistant();
							Assistants->push(newAssistant);
						}
						modifiedChanceOfAppearanceD *= (100.f - lowerPricePercent * 0.5) * 0.01;
						if (isAdsOn)
							modifiedChanceOfAppearanceD *= 0.9;
						modifiedChanceOfAppearanceD /= 2;
						modifiedChanceOfAppearanceInt = static_cast<int>(modifiedChanceOfAppearanceD);

						// Первый приход людей
						peopleCreatedRandom =
							howMuchTimesOccured(modifiedChanceOfAppearanceInt, modellingTime * 100, 0);
						peopleCreated = peopleCreatedRandom.first;
						timeleft = peopleCreatedRandom.second;
						nextGuestsComingTime = modellingTime - timeleft;

						modellingTimeFixQueues = modellingTime / 5;
						start = modelTime.getElapsedTime();

					}
					else // Количество продавцов +
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 20 && event.mouseButton.y <= 60
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							SellersCount += 1;
							if (SellersCount > 7) SellersCount = 7;
						}
					else // Количество продавцов -
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 60 && event.mouseButton.y <= 100
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							SellersCount -= 1;
							if (SellersCount < 1) SellersCount = 1;
						}
					else // Количество консультантов +
						if (event.mouseButton.x >= 615 && event.mouseButton.x <= 665
							&& event.mouseButton.y >= 20 && event.mouseButton.y <= 60
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							AssistantsCount += 1;
							if (AssistantsCount > 7) AssistantsCount = 7;
						}
					else // Количество консультантов -
						if (event.mouseButton.x >= 615 && event.mouseButton.x <= 665
							&& event.mouseButton.y >= 60 && event.mouseButton.y <= 100
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							AssistantsCount -= 1;
							if (AssistantsCount < 1) AssistantsCount = 1;
						}
					else // Время моделирования +
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 120 && event.mouseButton.y <= 160
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							modellingTime += 10;
							if (modellingTime > 60) modellingTime = 60;
						}
					else // Время моделирования -
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 160 && event.mouseButton.y <= 200
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							modellingTime -= 10;
							if (modellingTime < 10) modellingTime = 10;
						}
					else // Минимальная покупка +
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 220 && event.mouseButton.y <= 260
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							priceCostMin += 20;
						}
					else // Минимальная покупка -
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 260 && event.mouseButton.y <= 300
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							priceCostMin -= 20;
							if (priceCostMin < 10) priceCostMin = 10;
						}
					else // Максимальная покупка +
						if (event.mouseButton.x >= 385 && event.mouseButton.x <= 435
							&& event.mouseButton.y >= 220 && event.mouseButton.y <= 260
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							priceCostMax += 250;
						}
					else // Максимальная покупка -
						if (event.mouseButton.x >= 385 && event.mouseButton.x <= 435
							&& event.mouseButton.y >= 260 && event.mouseButton.y <= 300
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							priceCostMax -= 250;
							if (priceCostMin > priceCostMax) priceCostMax = priceCostMin + 250;
						}
					else // Скидки +
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 320 && event.mouseButton.y <= 360
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							lowerPricePercent += 5;
							if (lowerPricePercent > 75) lowerPricePercent = 75;
						}
					else // Скидки -
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 360 && event.mouseButton.y <= 400
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							lowerPricePercent -= 5;
							if (lowerPricePercent < 0) lowerPricePercent = 0;
						}
					else // Скидки -
						if (event.mouseButton.x >= 235 && event.mouseButton.x <= 285
							&& event.mouseButton.y >= 435 && event.mouseButton.y <= 475
							&& event.mouseButton.button == sf::Mouse::Button::Left) {
							isAdsOn = !isAdsOn;
							if (isAdsOn) {
								buttonIfAds->setFillColor(*darkGreen);
								textIsAds->setString("V");
							}
							else {
								buttonIfAds->setFillColor(*darkRed);
								textIsAds->setString("X");
							}
						}
					// Ограничение выхода за нужные границы
				}
			}

			// Отрисовка объектов (Можно скрыть)
#pragma region drawStuff
			window.clear();
			window.draw(*background);
//			window.draw(*BGOptionsDebug);

			sf::Text * textSellersCount = new sf::Text(std::to_string(SellersCount), font, 25);
			textSellersCount->setPosition(300.0, 50.0);
			textSellersCount->setFillColor(sf::Color::Black);

			window.draw(*buttonPlusSeller);
			window.draw(*textPlusSeller);
			window.draw(*buttonMinusSeller);
			window.draw(*textMinusSeller);
			window.draw(*textSellersCount);
			window.draw(*textNumberOfSellers);
			textSellersCount = NULL;

			sf::Text * textAssistantsCount = new sf::Text(std::to_string(AssistantsCount), font, 25);
			textAssistantsCount->setPosition(680.0, 50.0);
			textAssistantsCount->setFillColor(sf::Color::Black);

			window.draw(*buttonPlusAssistant);
			window.draw(*textPlusAssistant);
			window.draw(*buttonMinusAssistant);
			window.draw(*textMinusAssistant);
			window.draw(*textAssistantsCount);
			window.draw(*textNumberOfAssistants);
			window.draw(*textNumberOfAssistants2);
			textAssistantsCount = NULL;

			sf::Text * textModellingTimeNum =
				new sf::Text(std::to_string(modellingTime), font, 25);
			textModellingTimeNum->setPosition(300.0, 150.0);
			textModellingTimeNum->setFillColor(sf::Color::Black);

			window.draw(*buttonPlusModellingTime);
			window.draw(*textPlusModellingTime);
			window.draw(*buttonMinusModellingTime);
			window.draw(*textMinusModellingTime);
			window.draw(*textModellingTime1);
			window.draw(*textModellingTime2);
			window.draw(*textModellingTimeNum);
			textModellingTimeNum = NULL;

			sf::Text * textPriceCostNum =
				new sf::Text(std::to_string(priceCostMin), font, 25);
			textPriceCostNum->setPosition(300.0, 250.0);
			textPriceCostNum->setFillColor(sf::Color::Black);

			sf::Text * textPriceCostNum1 =
				new sf::Text(std::to_string(priceCostMax), font, 25);
			textPriceCostNum1->setPosition(450.0, 250.0);
			textPriceCostNum1->setFillColor(sf::Color::Black);

			window.draw(*buttonPlusPriceCost);
			window.draw(*textPlusPriceCost);
			window.draw(*buttonMinusPriceCost);
			window.draw(*textMinusPriceCost);
			window.draw(*buttonPlusPriceCost2);
			window.draw(*textPlusPriceCost2);
			window.draw(*buttonMinusPriceCost2);
			window.draw(*textMinusPriceCost2);
			window.draw(*textPriceCost11);
			window.draw(*textPriceCost12);
			window.draw(*textPriceCostNum);
			window.draw(*textPriceCostNum1);

			textPriceCostNum = NULL;
			textPriceCostNum1 = NULL;

			std::string strlowerPricePercent = std::to_string(lowerPricePercent);
			for (int i = 2; i < strlowerPricePercent.size(); i++) {
				strlowerPricePercent[i] = ' ';
			}
			sf::Text * textSalePercentNum =
				new sf::Text(strlowerPricePercent, font, 25);
			textSalePercentNum->setPosition(300.0, 350.0);
			textSalePercentNum->setFillColor(sf::Color::Black);

			window.draw(*buttonPlusSalePercent);
			window.draw(*textPlusSalePercent);
			window.draw(*buttonMinusSalePercent);
			window.draw(*textMinusSalePercent);
			window.draw(*textSalePercent1);
			window.draw(*textSalePercent2);
			window.draw(*textSalePercentNum);
			textSalePercentNum = NULL;

			window.draw(*buttonIfAds);
			window.draw(*textIsAds);
			window.draw(*textAds);

			window.draw(*buttonStartModel);
			window.draw(*textStartModelling);
			window.display();
#pragma endregion
		}
			break;

//###########################################################################################################################################
		case 1: {
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			sf::Time currentTime = modelTime.getElapsedTime() - start;
			float currentSeconds = currentTime.asSeconds();
			int modelminutes = static_cast<int>(currentSeconds * modellingTime);


			// Ежедневные выплаты. 1440 - количество минут в дне
			if (modelminutes / 1440 >= expectedDayUpdate) {
				expectedDayUpdate++;
				moneyResult -= moneyPaid * AssistantsCount * SellersCount;
				if (isAdsOn)	// TODO уровни рекламы?
					moneyResult -= moneyForAds;
			}
			if (expectedDayUpdate == 8) {
				screenSwitch = 2;
			}

			// Обновление информации происходит по периодам моделлирования
			if (modelminutes / modellingTime >= expectedGuestProceedPeriod) {
				expectedGuestProceedPeriod++;
				//**********************************************************//
				// Если гости были у кассы -> оплата + уход					//
				//**********************************************************//
				for (int i = 0; i < SellersCount; i++) {
					ShopQueue * thisQ = Terminals->operator[](i)->inf->getQueue();
					// times зависит от количества времени
					int times = howMuchTimesOccured(7, modellingTime, 1).first - 1;
					Guest * GuestToMove;
					do
					{
						GuestToMove = thisQ->pop();
						if (GuestToMove) {
							int paid = GuestToMove->getMoney();
							moneyResult += paid * moneyMultiplier;
							times--;
						}
					} while (GuestToMove && times > 0);
				}

				//**********************************************************//
				// Если гости были у консультантов -> к кассе				//
				//**********************************************************//
				for (int i = 0; i < AssistantsCount; i++) {
					ShopQueue * thisQ = Assistants->operator[](i)->inf->getQueue();
					// times зависит от количества времени
					int times = howMuchTimesOccured(7, modellingTime, 2).first - 1;
					Guest * GuestToMove;
					do
					{
						GuestToMove = thisQ->pop();
						if (GuestToMove) {
							Terminals->chooseLeastBusy()->getQueue()->push(GuestToMove);
							times--;
						}
					} while (GuestToMove && times > 0);
				}

				//**********************************************************//
				// Если гости были в зале -> к консультантам или к кассе	//
				//**********************************************************//
				Guest * GuestToMove;
				do
				{
					GuestToMove = Guests->pop();
					if (GuestToMove)
						if (GuestToMove->isConsulted()) {
							auto mostFree = Terminals->chooseLeastBusy()->getQueue();
							if ((mostFree->getCount() / modellingTimeFixQueues) > maxQSeller) {
								numberofGuestsLeft++;
								modifiedChanceOfAppearanceInt += 20;
							}
							else
								mostFree->push(GuestToMove);
						}
						else {
							auto mostFree = Assistants->chooseLeastBusy()->getQueue();
							if ((mostFree->getCount() / modellingTimeFixQueues) > maxQAssistant) {
								numberofGuestsLeft++;
								modifiedChanceOfAppearanceInt += 20;
							}
							else
								mostFree->push(GuestToMove);
						}

				} while (GuestToMove);
				for (int i = 0; i < GuestSprites.size(); i++) {
					GuestSprites[i] = NULL;
				}
				GuestSprites.clear();
				GuestSprites.resize(0);

				for (int i = 0; i < GuestSellerSprites.size(); i++) {
					GuestSellerSprites[i] = NULL;
				}
				GuestSellerSprites.clear();
				GuestSellerSprites.resize(0);

				for (int i = 0; i < GuestAssistantSprites.size(); i++) {
					GuestAssistantSprites[i] = NULL;
				}
				GuestAssistantSprites.clear();
				GuestAssistantSprites.resize(0);
				//**********************************************************//
				// Конец блока распределения покупателей					//
				//**********************************************************//
				// Начало блока запуска новых покупателей					//
				//**********************************************************//

				for (int i = 0; i < peopleCreated; i++) {
					// У каждого гостя имеется сумма денег в зависимости от выставленных параметров
					Guest * newGuest = 
						new Guest(priceCostMin, priceCostMax);
					Guests->push(newGuest);
					numberOfGuests++;
				}
				peopleCreatedRandom =
					howMuchTimesOccured(modifiedChanceOfAppearanceInt, nextGuestsComingTime, 0);
				peopleCreated = peopleCreatedRandom.first;
				timeleft = peopleCreatedRandom.second;
				nextGuestsComingTime = modellingTime * 100 - timeleft;

				// Округление дробных чисел
				moneyResult = round(moneyResult * 100) / 100;

				// Создание "спрайтов" гостей в зале в данном периоде
				for (int i = 0; i < Guests->getCount(); i++) {
					auto randval = rand();
					switch (randval % 4 + 1)
					{
					case 1:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest1T);
						thisSprite->setPosition(300.0 + randval % 178, 200.0 + randval % 100);
						GuestSprites.push_back(thisSprite);
					}
					break;

					case 2:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest2T);
						thisSprite->setPosition(300.0 + randval % 178, 200.0 + randval % 100);
						GuestSprites.push_back(thisSprite);
					}
					break;
					case 3:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest3T);
						thisSprite->setPosition(300.0 + randval % 178, 200.0 + randval % 200);
						GuestSprites.push_back(thisSprite);
					}
					break;
					default:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest4T);
						thisSprite->setPosition(300.0 + randval % 178, 200.0 + randval % 200);
						GuestSprites.push_back(thisSprite);
					}
					break;
					}
				}
				// Создание "спрайтов" гостей у консультанта в данном периоде
				for (int i = 0;
					 i < ((Assistants->front()->getQueue()->getCount() / modellingTimeFixQueues) + 1) * AssistantsCount;
					 i++) {
					auto randval = rand();
					switch (randval % 4 + 1)
					{
					case 1:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest1T);
						thisSprite->setPosition(50.0 + randval % 99, 210.0 + randval % 56);
						GuestAssistantSprites.push_back(thisSprite);
					}
					break;

					case 2:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest2T);
						thisSprite->setPosition(50.0 + randval % 99, 210.0 + randval % 56);
						GuestAssistantSprites.push_back(thisSprite);
					}
					break;
					case 3:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest3T);
						thisSprite->setPosition(50.0 + randval % 99, 210.0 + randval % 56);
						GuestAssistantSprites.push_back(thisSprite);
					}
					break;
					default:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest4T);
						thisSprite->setPosition(50.0 + randval % 99, 210.0 + randval % 56);
						GuestAssistantSprites.push_back(thisSprite);
					}
					break;
					}
				}
				// Создание "спрайтов" гостей у касс в данном периоде
				for (int i = 0; 
					 i < ((Terminals->front()->getQueue()->getCount() / modellingTimeFixQueues) + 1) * SellersCount;
					 i++) {
					auto randval = rand();
					switch (randval % 4 + 1)
					{
					case 1:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest1T);
						thisSprite->setPosition(80.0 + randval % 99, 360.0 + randval % 56);
						GuestSellerSprites.push_back(thisSprite);
					}
					break;

					case 2:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest2T);
						thisSprite->setPosition(80.0 + randval % 99, 360.0 + randval % 56);
						GuestSellerSprites.push_back(thisSprite);
					}
					break;
					case 3:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest3T);
						thisSprite->setPosition(80.0 + randval % 99, 360.0 + randval % 56);
						GuestSellerSprites.push_back(thisSprite);
					}
					break;
					default:
					{
						auto thisSprite = new sf::Sprite(*SpriteGuest4T);
						thisSprite->setPosition(80.0 + randval % 99, 360.0 + randval % 56);
						GuestSellerSprites.push_back(thisSprite);
					}
					break;
					}
				}
			}
			////////////////////////////////// Front-end /////////////////////////////////////////////

			//////////////////////////////////////////////////////////////////////////////////////////
#pragma region frontEndModel
			// Создание числовых параметров для вывода на экран
			std::string stringCurrentSeconds = std::to_string(currentSeconds);
			std::string stringModelMinutes = std::to_string(modelminutes);
			std::string stringNumberOfGuests = std::to_string(numberOfGuests);
			std::string stringMoneyGot = std::to_string(moneyResult);
			for (int i = 9; i < stringMoneyGot.size(); i++) {
				stringMoneyGot[i] = ' ';
			}
			//////////////////////Количество людей у каждого из продавцов////////////////////////
			std::string stringGuestsBuying;
			Seller* checkingBuying = Terminals->chooseLeastBusy();
			if (!checkingBuying)
				stringGuestsBuying = "0";
			else
				stringGuestsBuying =
					std::to_string((checkingBuying->getQueue()->getCount() / modellingTimeFixQueues) + 1); // Не превышает!!
																														  //////////////////////Количество людей у консультантов///////////////////////////////
			Seller* checkingAsking = Assistants->chooseLeastBusy();
			std::string stringGuestsAsking;
			if (!checkingAsking)
				stringGuestsAsking = "0";
			else
				stringGuestsAsking = 
					std::to_string((checkingAsking->getQueue()->getCount() / modellingTimeFixQueues) + 1); // Не превышает!!
																														  /////////////////////////////////////////////////////////////////////////////////////

			sf::Text * secondsAsText = new sf::Text(stringCurrentSeconds, font, 25);
			secondsAsText->setPosition(355.0, 15.0);
			secondsAsText->setFillColor(sf::Color::Black);

			sf::Text * modelMinutesAsText = new sf::Text(stringModelMinutes, font, 25);
			modelMinutesAsText->setPosition(355.0, 45.0);
			modelMinutesAsText->setFillColor(sf::Color::Black);

			sf::Text * textNumberOfGuests = new sf::Text(stringNumberOfGuests, font, 30);
			textNumberOfGuests->setPosition(625.0, 150.0);
			textNumberOfGuests->setFillColor(sf::Color::Black);

			sf::Text * textGuestsBuying = new sf::Text(stringGuestsBuying, font, 30);
			textGuestsBuying->setPosition(622.5, 290.0);
			textGuestsBuying->setFillColor(sf::Color::Black);

			sf::Text * textGuestsAsking = new sf::Text(stringGuestsAsking, font, 30);
			textGuestsAsking->setPosition(622.5, 375.0);
			textGuestsAsking->setFillColor(sf::Color::Black);

			sf::Text * textMoneyGot = new sf::Text(stringMoneyGot, font, 30);
			textMoneyGot->setPosition(625.0, 65.0);
			textMoneyGot->setFillColor(sf::Color::Black);

			sf::Text * textSellersActiveInt = new sf::Text(std::to_string(SellersCount), font, 25);
			textSellersActiveInt->setPosition(230.0, 520.0);
			textSellersActiveInt->setFillColor(sf::Color::Black);

			sf::Text * textAssistantsActiveInt = new sf::Text(std::to_string(AssistantsCount), font, 25);
			textAssistantsActiveInt->setPosition(230.0, 550.0);
			textAssistantsActiveInt->setFillColor(sf::Color::Black);

			sf::Text * textGuestsLeftInt = new sf::Text(std::to_string(numberofGuestsLeft), font, 25);
			textGuestsLeftInt->setPosition(480.0, 550.0);
			if (numberofGuestsLeft == 0)
				textGuestsLeftInt->setFillColor(sf::Color::Black);
			else
				textGuestsLeftInt->setFillColor(sf::Color(255,140,140,255)); // Темновато-красный

			//***************************************************************************//
			//						Создание графических объектов                        //
			//***************************************************************************//
			window.clear();
			window.draw(*background);
			window.draw(*BGShop);
			window.draw(*verticalLineStatistics);
			window.draw(*horizontalLineStatistics);
			window.draw(*horizontalLineMaxQ);
			window.draw(*horizontalLineBottomStatistics);
			//***************************************************************************//
			//				Текстовые строковые и числовые значения						 //
			//***************************************************************************//
			window.draw(*secondsAsText);
			window.draw(*modelMinutesAsText);
			window.draw(*textNumberOfGuests);
			window.draw(*textGuestsBuying);
			window.draw(*textGuestsAsking);
			window.draw(*textMoneyGot);
			window.draw(*textMoneyGotString1);
			window.draw(*textMoneyGotString2);
			window.draw(*textTimePassedInfo);
			window.draw(*textModelTimePassedInfo);
			window.draw(*textGuestsGotString1);
			window.draw(*textGuestsGotString2);
			window.draw(*textMaxQString1);
			window.draw(*textMaxQString2);
			window.draw(*textMaxQString3);
			window.draw(*textMaxQString4);
			window.draw(*textMaxQString5);
			window.draw(*textSellersActive);
			window.draw(*textSellersActiveInt);
			window.draw(*textAssistantsActive);
			window.draw(*textAssistantsActiveInt);
			window.draw(*textGuestsLeft);
			window.draw(*textGuestsLeft2);
			window.draw(*textGuestsLeftInt);
			//***************************************************************************//
			//							Работники и посетители							 //
			//***************************************************************************//
			for (int i = 0; i < GuestSprites.size(); i++) {
				window.draw(*GuestSprites[i]);
			}
			for (int i = 0; i < GuestAssistantSprites.size(); i++) {
				window.draw(*GuestAssistantSprites[i]);
			}
			for (int i = 0; i < GuestSellerSprites.size(); i++) {
				window.draw(*GuestSellerSprites[i]);
			}

			SpriteSeller->setPosition(70, 250);
			window.draw(*SpriteSeller);
			SpriteSeller->setPosition(50, 380);
			window.draw(*SpriteSeller);

			//window.draw(*night);
			window.display();
#pragma endregion
		}
		case 2:
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
		}
			break;
		default:
			break;
		}
	}
	return 0;
}