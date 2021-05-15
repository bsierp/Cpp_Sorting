/**
 * @file Exception.hh
 * @brief Plik zawiera definicje wyjątku nieposortowanej struktury
 * 
 */
#include<stdexcept>
/**
 * @brief Definicja prostego wyjątku nieposortowanej funkcji
 * 
 */
struct unsrt_error : public std::exception
{
    /**
     * @brief Zwraca wiadomość błędu
     * 
     * @return const char* - wiadomość błędu
     */
	const char * what () const throw ()
    {
    	return "Nieposortowane";
    }
};