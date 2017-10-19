#define SLAVE_LIST \
   X(0) \
   X(1) \
   X(2)

typedef struct Address {
   byte tx[6];
   byte rx[6];
} Address;

Address address[] = {
#define X(n) {#n "MOSI", #n "MISO"},
   SLAVE_LIST
#undef X
};

#define addressCount sizeof(address)/sizeof(Address)

