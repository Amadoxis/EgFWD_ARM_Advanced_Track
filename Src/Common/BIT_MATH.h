#define  SET_BIT(var,bit_number)    var|= (1<<bit_number)
#define  CLR_BIT(var,bit_number)    var&=~(1<<bit_number)
#define  TGL_BIT(var,bit_number)    var^=(1<<bit_number)
#define  GET_BIT(var,bit_number)    1&(var>>bit_number)

#define  UPP_NBB(var,data)           (var&0x0F)|(data&0xF0)
#define  LOW_NBB(var,data)           (var&0x0F)|(data<<4)
