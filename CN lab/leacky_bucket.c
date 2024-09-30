#include <stdio.h>
#include <unistd.h>

struct LeakyBucket {
    int bucket_capacity;
    int output_rate;
    float current_water;
    float last_checked;
};

void initialize(struct LeakyBucket *bucket, int capacity, int rate) {
    bucket->bucket_capacity = capacity;
    bucket->output_rate = rate;
    bucket->current_water = 0;
    bucket->last_checked = (float)time(NULL);
}

void add_packet(struct LeakyBucket *bucket, int packet_size) {
    float current_time = (float)time(NULL);
    float time_passed = current_time - bucket->last_checked;
    float leaked_amount = time_passed * bucket->output_rate;

    bucket->current_water -= leaked_amount;
    if (bucket->current_water < 0) bucket->current_water = 0;
    bucket->last_checked = current_time;

    if (bucket->current_water + packet_size <= bucket->bucket_capacity) {
        bucket->current_water += packet_size;
        printf("Packet of size %d added. Current bucket level: %.2f\n", packet_size, bucket->current_water);
    } else {
        printf("Packet of size %d dropped. Bucket overflow.\n", packet_size);
    }
}

int main() {
    struct LeakyBucket bucket;
    initialize(&bucket, 100, 1);

    int packets[] = {20, 50, 40, 6, 20};
    int num_packets = sizeof(packets) / sizeof(packets[0]);

    for (int i = 0; i < num_packets; i++) {
        sleep(1);
        add_packet(&bucket, packets[i]);
    }

    return 0;
}
