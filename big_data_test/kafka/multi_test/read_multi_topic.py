from kafka import KafkaConsumer

# Topic 1 Consumer
consumer_topic1 = KafkaConsumer(
    'multi_topic_1'
    , bootstrap_servers=['localhost:9092', 'localhost:9093', 'localhost:9094']
    , auto_offset_reset='earliest'
    , group_id='group1'
    , consumer_timeout_ms=5000 # 5초 동안 메시지가 없으면 종료
)

# Topic 2 Consumer
consumer_topic2 = KafkaConsumer(
    'multi_topic_2'
    , bootstrap_servers=['localhost:9092', 'localhost:9093', 'localhost:9094']
    , auto_offset_reset='earliest'
    , group_id='group2'
    , consumer_timeout_ms=5000 # 5초 동안 메시지가 없으면 종료
)

# Topic 1 메시지 읽기
print("Reading messages from topic1...")
for message in consumer_topic1:
    print(f"Topic 1: {message.value.decode('utf-8')}")

# Topic 2 메시지 읽기
print("Reading messages from topic2...")
for message in consumer_topic2:
    print(f"Topic 2: {message.value.decode('utf-8')}")