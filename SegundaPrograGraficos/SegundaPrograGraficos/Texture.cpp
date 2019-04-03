 //
//  Texture.cpp
//  SegundaPrograGraficos
//
//  Created by Jafeth  Vásquez on 4/3/19.
//  Copyright © 2019 Jafeth Vásquez. All rights reserved.
//

#include "Texture.hpp"

Texture::Texture(const string& path):
m_FilePath(path),
m_LocalBuffer(nullptr),
m_Width(0),
m_Height(0),
m_BPP(0)
{
    
}

Texture::~Texture()
{
    
}

void Texture::Bind(unsigned int slot) const
{
    
}

void Texture::Unbind() const{
    
}
