#ifndef __DEBOUNCE_H__
#define __DEBOUNCE_H__


/************** funkcja SuperDebounce do obsługi pojedynczych klawiszy ***************
 * 							AUTOR: Mirosław Kardaś
 * ZALETY:
 * 		- nie wprowadza najmniejszego spowalnienia
 * 		- posiada funkcję REPEAT (powtarzanie akcji dla dłużej wciśniętego przycisku)
 * 		- można przydzielić róne akcje dla trybu REPEAT i pojedynczego kliknięcia
 * 		- można przydzielić tylko jedną akcję wtedy w miejsce drugiej przekazujemy 0 (NULL)
 *
 * Wymagania:
 * 	Timer programowy utworzony w oparciu o Timer sprzętowy (przerwanie 100Hz)
 *
 * 	Parametry wejściowe:
 *
 * 	*key_state - wskaźnik na zmienną w pamięci RAM (1 bajt) - do przechowywania stanu klawisza
 *  *KPIN - nazwa PINx portu na którym umieszczony jest klawisz, np: PINB
 *  key_mask - maska klawisza np: (1<<PB3)
 *  rep_time - czas powtarzania funkcji rep_proc w trybie REPEAT
 *  rep_wait - czas oczekiwania do przejścia do trybu REPEAT
 *  push_proc - wskaźnik do własnej funkcji wywoływanej raz po zwolenieniu przycisku
 *  rep_proc - wskaźnik do własnej funkcji wykonywanej w trybie REPEAT
 **************************************************************************************/
void SuperDebounce( uint8_t* key_state, 
                    volatile uint8_t* KPIN, 
                    uint8_t key_mask, 
                    uint16_t rep_time, 
                    uint16_t rep_wait,
                    void (*push_proc)(void), 
                    void (*rep_proc)(void)
);


#endif