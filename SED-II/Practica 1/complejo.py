class Complejo:
    def __init__(self, real = 0, imag = 0):
        self.real = real
        self.imag = imag

    def get_real(self):
        return self.real

    def set_real(self,real):
        self.real = real 
    
    def get_imag(self):
        return self.imag
    
    def set_imag(self, imag):
        self.imag = imag
    
    def __str__(self):
        return f"({self.real} + {self.imag}i)"

    def __add__(self,other):
        real = self.real + other.real
        imag = self.imag + other.imag
        return Complejo(real,imag)

    def __sub__(self,other):
        real = self.real - other.real 
        imag = self.imag - other.imag
        return Complejo(real,imag)

    def __mul__(self,other):
        real = self.real * other.real - self.imag * other.imag
        imag = self.real * other.imag + other.real * self.imag
        return Complejo(real,imag)