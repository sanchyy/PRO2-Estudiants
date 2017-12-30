std::vector<std::string> addBorder(std::vector<std::string> picture) {
    int max_length = picture[0].length();
    
    string s = "";
    //escriure linia = mida paraula d'*
    for(int i = 0; i < max_length; ++i) s += "*";
   //primera i ultima fila son asteriscs
    picture.insert(picture.begin(), s);
    picture.insert(picture.end(), s);
    //primera i ultima columna asteriscs
    for(int i = 0; i < picture.size(); ++i)
        picture[i] = "*" + picture[i] + "*";

    return picture;
}