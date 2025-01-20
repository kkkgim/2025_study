from kafka import KafkaProducer
import time

# Kafka Producer 생성
producer = KafkaProducer(bootstrap_servers=['localhost:9092', 'localhost:9093', 'localhost:9094'])

# 여러 Topic으로 메시지 전송
topics = ['multi_topic_1', 'multi_topic_2']

for i in range(10):  # 10개의 메시지 전송
    for topic in topics:
        message = f"Message {i} for {topic}"
        producer.send(topic, message.encode('utf-8'))
        print(f"Sent to {topic}: {message}")
    time.sleep(1)  # 1초 대기