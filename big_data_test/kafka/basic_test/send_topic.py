from kafka import KafkaProducer

# Kafka Producer 생성
producer = KafkaProducer(bootstrap_servers='localhost:9092')

print(' Start sending messages now. Type "end" to stop. ')
# 메세지 전송
while True:
    txt = str(input())

    if txt == 'end':
        break
    producer.send('test-topic', txt.encode('ascii'))
    producer.flush()  # 메시지를 즉시 전송