#ifndef ESTUDIANT_HH
#define ESTUDIANT_HH

#include <iostream>
#include "PRO2Excepcio.hh"
using namespace std;

class Estudiant {

  // Tipus de mòdul: dades
  // Descripció del tipus: conté el DNI d'un estudiant, 
  // que és un enter positiu, pot tenir nota (que seria un double)   
  // i una beca. 
  // Les notes vàlides són les de l'interval 0...nota_maxima(). 

private:    
  int dni;
  double nota;
  bool amb_nota;
  bool amb_beca;
  static const int MAX_NOTA = 10;
  static const int MIN_APR = 5.0;
  /* 
     Invariant de la representació: 
     - 0 <= dni
     - si amb_nota és true, llavors 0 <= nota <= MAX_NOTA 
     - si amb_beca és true, llavors amb_nota és true i nota >= MIN_APR
  */


public:


  //Constructors

  Estudiant();
  /* Pre: cert */ 
  /* Post: el resultat és un estudiant amb DNI = 0, sense nota i sense beca */

  Estudiant(int dni);
  /* Pre: dni >= 0 */ 
  /* Post: el resultat és un estudiant amb DNI = dni, sense nota i sense beca */

  // Destructora: esborra automàticament els objectes locals en sortir 
  // d'un àmbit de visibilitat
  ~Estudiant();


  // Modificadors

  void afegir_nota(double n);
  /* Pre: el paràmetre implícit no té nota, 0 <= n <= nota_maxima() */
  /* Post: la nota del paràmetre implícit passa a ser n */
   
  void modificar_nota(double n);
  /* Pre: el paràmetre implícit té nota, 0 <= n <= nota_maxima() */
  /* Post: la nota del paràmetre implícit passa a ser n */

  void modificar_beca(bool v);
  /* Pre: cert */
  /* Post: si v és true el paràmetre implícit passa a tenir beca;
     altrament, el p.i. passa a no tenir beca */
                                    

  // Consultors

  int consultar_DNI() const;
  /* Pre: cert  */
  /* Post: el resultat és el DNI del paràmetre implícit */

  double consultar_nota() const;
  /* Pre: el paràmetre implícit té nota */
  /* Post: el resultat és la nota del paràmetre implícit */

  static double nota_maxima();
  /* Pre: cert */
  /* Post: el resultat és la nota màxima dels elements de la classe */

  bool te_nota() const;
  /* Pre: cert  */
  /* Post: el resultat indica si el paràmetre implícit té nota o no */

  bool te_beca() const;
  /* Pre: cert  */
  /* Post: el resultat indica si el paràmetre implícit té beca o no */

  bool aprovat() const; 
  /* Pre: cert */
  /* Post: el resultat indica si el paràmetre implícit està aprovat */

  static bool menor_dni(const Estudiant& e1, const Estudiant& e2);
  /* Pre: cert  */
  /* Post: El resultat és cert si el dni d'e1 és menor que el dni
     d'e2; */
  
  static bool major_nota_dni(const Estudiant& e1, const Estudiant& e2); 
  /* Pre: cert  */
  /* Post: El resultat és cert si: 
        1) la nota d'e1 és mes gran que la nota d'e2; 
        2) les notes d'e1 i e2 son iguals, i el dni d'e1 és major que 
           el dni d'e2; 
        3) e1 té nota i e2 no té nota; 
        4) e1 i e2 no tenen nota, i el dni d'e1 és major que el dni d'e2. 
     En qualssevol altre cas el resultat és fals. */


  // Lectura i escriptura

  void llegir();
  /* Pre:  hi ha preparats al canal estandar d'entrada un enter no negatiu 
     i un double */
  /* Post: el paràmetre implícit passa a tenir els atributs llegits 
     del canal estàndard d'entrada; si el double no pertany a l'interval 
     [0..nota_maxima()], el p.i. es queda sense nota; el p.i. no té beca */

  void escriure() const;
  /* Pre: cert */
  /* Post: s'han escrit els atributs del paràmetre implícit al canal
     estàndard de sortida; si no té nota escriu "NP"; si té beca
     escriu "amb beca" */
};
#endif
