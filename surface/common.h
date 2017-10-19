#define SLAVE_LIST \
   X(0) \
   X(1) \
   X(2)

typedef struct Address {
   const byte tx[6];
   const byte rx[6];
} Address;

Address address[] = {
#define X(n) {#n "MISO", #n "MOSI"},
   SLAVE_LIST
#undef X
};

#define addressCount sizeof(address)/sizeof(Address)

