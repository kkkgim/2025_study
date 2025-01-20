from kafka import KafkaConsumer

# Kafka Consumer 생성
consumer = KafkaConsumer(
    'test-topic'
    , bootstrap_servers='localhost:9092'
    , auto_offset_reset='earliest'  # 마지막 offset부터 읽음
    , group_id='test-group-2'
    , consumer_timeout_ms=5000 # 5초 동안 메시지가 없으면 종료
)

# 메시지 읽기
for message in consumer:
    print(f"받은 메시지: {message.value.decode('utf-8')}")

print('end get consumer')