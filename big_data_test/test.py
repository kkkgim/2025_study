
from pyspark.sql import SparkSession
from pyspark.sql.functions import explode, split, col, count

# PySpark 세션 생성
spark = SparkSession.builder.appName("WordCount").getOrCreate()

# HDFS에서 텍스트 파일 읽기
df = spark.read.text("hdfs://localhost:9000/user/mapreduce/input/ebook.txt")

# 각 줄을 단어로 분리하여 "word" 컬럼 생성
words_df = df.select(explode(split(col("value"), " ")).alias("word"))

# 각 단어의 발생 횟수 계산
word_counts_df = words_df.groupBy("word").agg(count("word").alias("count"))

# 결과 출력
word_counts_df.show(truncate=False)

# Spark 세션 종료
# spark.stop()