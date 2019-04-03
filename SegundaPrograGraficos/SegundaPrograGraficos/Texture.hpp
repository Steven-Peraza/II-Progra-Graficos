//
//  Texture.hpp
//  SegundaPrograGraficos
//
//  Created by Jafeth  Vásquez on 4/3/19.
//  Copyright © 2019 Jafeth Vásquez. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <stdio.h>
#include <GLUT/GLUT.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Texture
{
private:
    string m_FilePath;
    unsigned char* m_LocalBuffer;
    int m_Width, m_Height, m_BPP;
    
public:
    
    Texture(const string& path);
    ~Texture();
    
    void Bind(unsigned int slot = 0) const;
    void Unbind()const;
    
    inline int GetWitdh() const {return m_Width;}
    inline int GetWHeight() const {return m_Height;}
    
    
};

#endif /* Texture_hpp */
