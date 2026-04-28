#include <iostream>
#include <ctime>
#include <string>
#include <cstdlib> // pour atoi() et labs()

// Fonction pour convertir une date "AAAA-MM-JJ" en timestamp
time_t convertDateToTimestamp(const std::string& date) {
	struct tm tm = {0};
	tm.tm_year = atoi(date.substr(0, 4).c_str()) - 1900;
	tm.tm_mon = atoi(date.substr(5, 2).c_str()) - 1;
	tm.tm_mday = atoi(date.substr(8, 2).c_str());
	tm.tm_hour = 0;
	tm.tm_min = 0;
	tm.tm_sec = 0;
	tm.tm_isdst = -1; // DST auto-détection

	return mktime(&tm);
}

// Fonction pour trouver la date la plus proche
std::string findClosestDate(const std::string& reference,
						   const std::string& date1,
						   const std::string& date2) {
	// Conversion en timestamps
	time_t ref = convertDateToTimestamp(reference);
	time_t t1 = convertDateToTimestamp(date1);
	time_t t2 = convertDateToTimestamp(date2);

	// Calcul des différences (en valeur absolue) avec labs() pour les long
	long diff1 = labs(ref - t1);
	long diff2 = labs(ref - t2);

	// Retourne la date la plus proche
	return (diff1 < diff2) ? date1 : date2;
}

int main() {
	std::string refDate = "2010-12-03";
	std::string date1 = "2011-01-04";
	std::string date2 = "2010-11-05";

	std::string closest = findClosestDate(refDate, date1, date2);

	std::cout << "Entre '" << date1 << "' et '" << date2 << "'" << std::endl;
	std::cout << "La date la plus proche de '" << refDate << "' est: " << closest << std::endl;

	return 0;
}
