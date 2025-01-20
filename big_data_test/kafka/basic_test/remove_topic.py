from kafka.admin import KafkaAdminClient

# Kafka Admin Client 생성
admin_client = KafkaAdminClient(
    bootstrap_servers="localhost:9092",
    client_id='test-admin'
)

# 토픽 삭제
topic_to_delete = ["test-topic"]
admin_client.delete_topics(topics=topic_to_delete)

print("토픽이 성공적으로 삭제되었습니다!")