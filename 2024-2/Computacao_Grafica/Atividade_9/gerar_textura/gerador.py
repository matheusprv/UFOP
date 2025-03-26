from PIL import Image

imagem_original = Image.open('Atividade_9/gerar_textura/73c4f7031744129.png').convert('RGB')

# Redimensiona para 256x256 usando alta qualidade
imagem_redimensionada = imagem_original.resize((256, 256), Image.LANCZOS)

# Garante que a imagem esteja no formato RGB (sem transparência)
imagem_final = Image.new('RGB', (256, 256))
imagem_final.paste(imagem_redimensionada)

# Salva no formato BMP (compatível com seu código OpenGL)
imagem_final.save('texture.bmp', format='BMP')
